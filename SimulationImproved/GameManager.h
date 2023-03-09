#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "Light.h"
#include "Keyboard.h"
#include <algorithm>
#include "imgui\\imgui.h"
#include "imgui\\imgui_impl_dx11.h"
#include "imgui\\imgui_impl_win32.h"

using namespace DirectX;
using namespace std;

class GameManager
{
private:
	std::vector<Camera> cameras;
	std::vector<GameObject> entities;
	float timescale;
	float timeSinceExplosion;
	const float collisionRadius = 0.3f;
	const float explosionRadius = 1.f;
	int width;
	int height;
	bool isRocketLaunched;
	bool canFire;
	bool isEngineOn;
	bool isReset;
	std::unique_ptr<DirectX::Keyboard> keyboard{};

	//Camera pointers
	Camera* activeCam;
	Camera* rocketCam;
	Camera* rocketNoseCam;
	Camera* rocketBodyCam;

	//Entity pointers
	GameObject* rocket;
	GameObject* terrain;
	GameObject* sun;
	GameObject* moon;
	GameObject* explosion;
	GameObject* launcher;
	GameObject* smoke;

	void CheckInput(const float& dt);
	void HandleCameraInput(const DirectX::Keyboard::State& keyBoard, const float& dt);
	void CreateCameras();
	void CreateTerrain();
	void CreateRocket();
	void CheckRocketCollision();
	void SpawnExplosionParticles(const XMFLOAT3& position);
	void CreateParticles(const DirectX::XMFLOAT3& position, const std::vector<InstanceData>* const& smokeInstancesPointer, std::vector<InstanceData>* const& explosionInstancesPointer);
	void AssignObjects();
	void UpdateRocket(const float& dt);
	void HandleCamera(const float& dt);
	void ResetRocketCams()const;
	void RemoveVoxels(const vector<InstanceData> &data, const XMFLOAT3 &conePos);

public:
	GameManager();
	GameManager(const int& width, const int& height);
	~GameManager();
	void InitScene();
	void CreateMoon();
	void CreateSun();
	void CreateLauncherStick();
	void ResetScene();
	void Update(const float& dt);

	bool IsExit;

	const Camera* const ActiveCamera() const;
	const std::vector<GameObject>& Entities() const;

	GameManager& operator=(const GameManager&) = delete;
	GameManager(const GameManager&) = delete;
};