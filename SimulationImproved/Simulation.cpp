#include <windows.h>
#include "GameManager.h"
#include "GraphicsManager.h"
#include <chrono>

//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               g_hInst = nullptr;
HWND                    g_hWnd = nullptr;

//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI wWinMain(_In_ const HINSTANCE hInstance, _In_opt_ const HINSTANCE hPrevInstance, _In_ const LPWSTR lpCmdLine, _In_ const int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (FAILED(InitWindow(hInstance, nCmdShow)))
		return 0;

	//Gives renderer pointer to window
	GraphicsManager renderer;
	renderer.SetWindow(g_hWnd);

	if (FAILED(renderer.InitDXDevice()))
	{
		renderer.CleanUpDevice();
		return 0;
	}

	GameManager gm(renderer.Width(), renderer.Height());

	//Main message loop
	MSG msg = { 0 };
	auto previousTime = std::chrono::high_resolution_clock::now();
	auto startTime = std::chrono::high_resolution_clock::now();
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{	
			//Calculates delta time
			auto currentTime = std::chrono::high_resolution_clock::now();
			const auto elapsedTimeTotal = currentTime - startTime;
			const auto elapsedTime = currentTime - previousTime;
			const float dt = (elapsedTime.count() / 1e+9);
			const float time = (elapsedTimeTotal.count() / 1e+9);

			//Update Render Loop
			gm.Update(dt);

			if (gm.IsExit)
			{
				renderer.CleanUpDevice();
				return 0;
			}
			if (FAILED(renderer.Render(gm.Entities(), gm.ActiveCamera(), time)))
			{
				renderer.CleanUpDevice();
				return 0;
			}
			previousTime = currentTime;
		}
		if (renderer.IsInitialized())
		{
			gm.ResetScene();
			renderer.ChangeInputState(false);
		}
	}
	
	//Cleanup device on exit
	renderer.CleanUpDevice();

	return static_cast<int>(msg.wParam);
}


HRESULT InitWindow(const HINSTANCE hInstance, const int nCmdShow)
{
	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"Simulation";
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
	if (!RegisterClassEx(&wcex))
		return static_cast<HRESULT>(0x80004005L);

	// Create window
	g_hInst = hInstance;
	RECT rc = { 0, 0, 1366, 768 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	g_hWnd = CreateWindow(L"Simulation", L"Simulation",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
		nullptr);
	if (!g_hWnd)
		return static_cast<HRESULT>(0x80004005L);

	ShowWindow(g_hWnd, nCmdShow);

	return static_cast<HRESULT>(0L);
}


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND  hwnd, UINT  umsg, WPARAM wparam, LPARAM  lparam);

LRESULT CALLBACK WndProc(const HWND hWnd, const UINT message, const WPARAM wParam, const LPARAM lParam)
{	
	//if (TwEventWin(hWnd, message, wParam, lParam))
	//{
	//	return 0;
	//}

	if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
		return true;


	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	//DirectXTK input handling
	case WM_ACTIVATEAPP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		break;

	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}