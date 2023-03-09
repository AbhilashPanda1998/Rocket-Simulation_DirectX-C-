#pragma once

#include <vector>
#include <map>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "DDSTextureLoader.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Camera.h"
#include "Light.h"
#include <Keyboard.h>
#include "imgui\\imgui.h"
#include "imgui\\imgui_impl_dx11.h"
#include "imgui\\imgui_impl_win32.h"

using namespace std;
using namespace DirectX;

//Constant buffer for passing data to the shader
struct ConstantBuffer
{
	XMFLOAT4X4 mWorld;
	XMFLOAT4X4 mWorldInverse;
	XMFLOAT4X4 mView;
	XMFLOAT4X4 mProjection;
	XMFLOAT4 vLightPos[4];
	XMFLOAT4 vLightColour[4];
	XMFLOAT4 vCameraPos;
	float numOfLights;
	float time;
	DirectX::XMFLOAT2 padding;
};


class GraphicsManager 
{
private:
	map<wstring, ID3D11VertexShader*>			mVertexShaders;
	map<wstring, ID3D11PixelShader*>			mPixelShaders;
	map<MeshType, ID3D11Buffer*>				mVertexBuffers;
	map<MeshType, ID3D11Buffer*>				mIndexBuffers;
	map<string, ID3D11Buffer*>				mInstanceBuffers;
	map<wstring, ID3D11ShaderResourceView*>	mTextures;
	map<wstring, ID3D11InputLayout*>			mLayouts;
	int													mWidth;
	int													mHeight;
	D3D_DRIVER_TYPE										mDriverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL									mFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	HWND												mWnd = nullptr;
	ID3D11Device*										mD3dDevice = nullptr;
	ID3D11Device1*										mD3dDevice1 = nullptr;
	ID3D11DeviceContext*								mImmediateContext = nullptr;
	ID3D11DeviceContext1*								mImmediateContext1 = nullptr;
	IDXGISwapChain*										mSwapChain = nullptr;
	IDXGISwapChain1*									mSwapChain1 = nullptr;
	ID3D11RenderTargetView*								mRenderTargetView = nullptr;
	ID3D11Texture2D*									mDepthStencil = nullptr;
	ID3D11DepthStencilView*								mDepthStencilView = nullptr;
	ID3D11DepthStencilState*							mDepthStencilLessThanEqual = nullptr;
	ID3D11RasterizerState*								mRasteriserStateNoCull = nullptr;
	ID3D11RasterizerState*								mRasteriserStateBackCull = nullptr;
	ID3D11BlendState*									mBlendStateAlpha = nullptr;
	ID3D11BlendState*									mBlendStateDisable = nullptr;
	ID3D11Buffer*										mConstantBuffer = nullptr;
	D3D11_BUFFER_DESC									mBufferDesc;
	ID3D11SamplerState*									mSampler = nullptr;
	ConstantBuffer										cb1;

	bool isInitiliazed;
	void SetLights(const Light& light);
	void SetCamera(const Camera* camera);
	HRESULT VertexIndex(const Mesh& shape);
	HRESULT Texture(const Mesh& shape);
	HRESULT Shader(const Mesh& shape);
	HRESULT CompileShaderFromFile(const WCHAR* const szFileName, const LPCSTR szEntryPoint, const LPCSTR szShaderModel, ID3DBlob** const ppBlobOut) const;

public:
	GraphicsManager();
	~GraphicsManager();

	const int& Width() const;
	const int& Height() const;

	void SetWindow(const HWND& Wnd);
	HRESULT InitDXDevice();
	HRESULT Render(const std::vector<GameObject>& entities, const Camera* const camera, const float& time);
	void CleanUpDevice();

	GraphicsManager& operator=(const GraphicsManager&) = delete;
	GraphicsManager(const GraphicsManager&) = delete;

	void ChangeInputState(bool value) { isInitiliazed = value; }
	bool IsInitialized() { return isInitiliazed; }
};