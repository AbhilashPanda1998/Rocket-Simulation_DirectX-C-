#include "GameManager.h"

using namespace std;
using namespace DirectX;


void GameManager::CheckInput(const float& dt)
{
	//Gets state of keyboard
	const auto keyBoard = keyboard->GetState();

	//Close application key
	if (keyBoard.Escape)
	{
		IsExit = true;
	}

	//Reset scene to inital state
	if (keyBoard.R)
	{
		ResetScene();
	}

	if (keyBoard.T && !keyBoard.LeftShift)
	{
		timescale -= 0.1f;
		if (timescale <= 0) timescale = 1;
	}

	if (keyBoard.T && keyBoard.LeftShift)
	{
		timescale += 0.1f;
	}

	//Camera selection

	if (keyBoard.F1)
	{
		activeCam = &cameras[0];
	}
	if (keyBoard.F2)
	{
		activeCam = &cameras[1];
	}
	if (keyBoard.F3)
	{
		activeCam = &cameras[2];
	}
	if (keyBoard.F4)
	{
		activeCam = &cameras[3];
	}
	if (keyBoard.F5)
	{
		activeCam = &cameras[4];
	}

	HandleCameraInput(keyBoard, dt);


	if (keyBoard.OemPeriod && keyBoard.LeftShift && !isRocketLaunched)
	{
		rocket->RotateEntity(XMFLOAT3(0, 0, XMConvertToRadians(-5)), timescale, dt);
		launcher->RotateEntity(XMFLOAT3(0, 0, XMConvertToRadians(-5)), timescale, dt);
		rocketNoseCam->SetLookAt(rocket->Shapes()[1].WorldPos());
	}
	if (keyBoard.OemComma && keyBoard.LeftShift && !isRocketLaunched)
	{
		rocket->RotateEntity(XMFLOAT3(0, 0, XMConvertToRadians(5)), timescale, dt);
		launcher->RotateEntity(XMFLOAT3(0, 0, XMConvertToRadians(5)), timescale, dt);
		rocketNoseCam->SetLookAt(rocket->Shapes()[1].WorldPos());
	}


	if (keyBoard.F11 && canFire)
	{
		isRocketLaunched = true;
		canFire = false;
	}
}

void GameManager::HandleCameraInput(const DirectX::Keyboard::State& keyBoard, const float& dt)
{
	
	if (keyBoard.W && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(activeCam->Forward(), dt);
	}
	if (keyBoard.A && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(XMFLOAT3(-activeCam->Right().x, -activeCam->Right().y, -activeCam->Right().z), dt);
	}
	if (keyBoard.S && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(XMFLOAT3(-activeCam->Forward().x, -activeCam->Forward().y, -activeCam->Forward().z), dt);
	}
	if (keyBoard.D && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(activeCam->Right(), dt);
	}
	if ((keyBoard.PageUp || keyBoard.Space) && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(activeCam->Up(), dt);
	}
	if ((keyBoard.PageDown || keyBoard.Q) && activeCam->AllowMovement() && keyBoard.LeftControl)
	{
		activeCam->MoveCamera(XMFLOAT3(-activeCam->Up().x, -activeCam->Up().y, -activeCam->Up().z), dt);
	}

	
	if (keyBoard.W && activeCam->AllowMovement() && !keyBoard.LeftControl)
	{
		activeCam->RotateCamera(XMFLOAT3(-XMConvertToRadians(5), 0, 0), dt);
	}
	if (keyBoard.A && activeCam->AllowMovement() && !keyBoard.LeftControl)
	{
		activeCam->RotateCamera(XMFLOAT3(0, -XMConvertToRadians(5), 0), dt);
	}
	if (keyBoard.S && activeCam->AllowMovement() && !keyBoard.LeftControl)
	{
		activeCam->RotateCamera(XMFLOAT3(XMConvertToRadians(5), 0, 0), dt);
	}
	if (keyBoard.D && activeCam->AllowMovement() && !keyBoard.LeftControl)
	{
		activeCam->RotateCamera(XMFLOAT3(0, XMConvertToRadians(5), 0), dt);
	}
}

void GameManager::CreateCameras()
{
	
	const float fov = XMConvertToRadians(60);
	const float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

	
	Camera newCamera(true, XMFLOAT3(10.5f, 15.5f, -13.0f), XMFLOAT3(0, 0, 0), fov, aspectRatio, 0.1f, 100.0f, 1.0f, 10.0f);
	cameras.push_back(newCamera);

	
	newCamera = Camera(true, XMFLOAT3(8.0f, 22.0f, 2.0f), XMFLOAT3(XMConvertToRadians(90), 0, 0), fov, aspectRatio, 0.1f, 100.0f, 1.0f, 10.0f);
	cameras.push_back(newCamera);

	
	newCamera = Camera(false, XMFLOAT3(0.5f, 8.2f, 1.0f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 2.5f, 2.4f), fov, aspectRatio, 0.1f, 100.0f, 1.0f, 10.0f);
	cameras.push_back(newCamera);

	
	newCamera = Camera(false, XMFLOAT3(0.5f, 7.2f, 2.0f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 3.0f, 2.4f), fov, aspectRatio, 0.1f, 100.0f, 1.0f, 10.0f);
	cameras.push_back(newCamera);

	
	newCamera = Camera(false, XMFLOAT3(0.5f, 6.2f, 2.0f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 2.4f, 2.4f), fov, aspectRatio, 0.1f, 100.0f, 1.0f, 10.0f);
	cameras.push_back(newCamera);

	//Sets pointers to cameras;
	activeCam = &cameras[0];
	rocketCam = &cameras[2];
	rocketNoseCam = &cameras[3];
	rocketBodyCam = &cameras[4];
}

void GameManager::CreateTerrain()
{
	vector<InstanceData> instances;
	for (int y = 0; y < 40; y++)
	{
		for (int z = 0; z < 30; z++)
		{
			for (int x = 0; x < 100; x++)
			{
				instances.emplace_back(InstanceData{ XMFLOAT3(x * 2, y * 2, z * 2) });
			}
		}
	}
	vector<InstanceData>* const instancesPointer = &instances;

	
	GameObject terrainObject(XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.1f, 0.1f, 0.1f), "Terrain", 0.0f, 0.0f);
	terrainObject.CreateShape(MeshType::CUBE, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1.0f, 1.0f, 1.0f), L"Floor_diffuse.dds", L"Floor_normal.dds", L"Floor_displacement.dds", L"TerrainShader.fx", "TerrainCube", &instances, false);
	entities.push_back(terrainObject);
	terrain = &terrainObject;
}

void GameManager::CreateRocket()
{
	GameObject rocketObject;
	rocketObject = GameObject(XMFLOAT3(0.5f, 8.2f, 3.0f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.1f, 0.1f, 0.1f), "Rocket", 1.5f, 2.0f);
	rocketObject.CreateShape(MeshType::CYLINDER, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 4.0f, 1), L"metal_diffuse.dds", L"metal_normal.dds", L"metal_displacement.dds", L"BumpShader.fx", "Cylinder", nullptr, false);
	rocketObject.CreateShape(MeshType::CONE, false, XMFLOAT3(0, 6.0f, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2.0f, 1), L"", L"", L"", L"ReflectiveShiny.fx", "Cone", nullptr, false);
	entities.push_back(rocketObject);
	rocket = &rocketObject;
	AssignObjects();
	ResetRocketCams();
}


void GameManager::CheckRocketCollision()
{
	const auto conePosF3 = rocket->Shapes()[1].WorldPos();
	const auto conePos = XMLoadFloat3(&conePosF3);
	const auto terrainTransformF4 = terrain->Transform();
	const auto terrainTransform = XMLoadFloat4x4(&terrainTransformF4);
	vector<InstanceData> terrainCubes = terrain->Shapes()[0].Instances();
	vector<InstanceData> cubesToRemove;
	auto collided = false;


	for (const auto& cube : terrainCubes)
	{
		const XMVECTOR cubePos = XMVector3Transform(XMLoadFloat3(&cube.Pos), terrainTransform);
		XMFLOAT3 distance;
		XMStoreFloat3(&distance, XMVector3Length(cubePos - conePos));
		if (distance.x < collisionRadius)
		{
			collided = true;
			for (const auto& cube : terrainCubes)
			{
				const auto cubePos = XMVector3Transform(XMLoadFloat3(&cube.Pos), terrainTransform);
				XMFLOAT3 distance;
				XMStoreFloat3(&distance, XMVector3Length(cubePos - conePos));
				if (distance.x < explosionRadius)
				{
					cubesToRemove.push_back(cube);
				}
			}
		}
	}
	RemoveVoxels(cubesToRemove, conePosF3);
}

void GameManager::SpawnExplosionParticles(const XMFLOAT3& position)
{
	
	vector<InstanceData> smokeInstances;
	for (int i = 0; i < 600; i++)
	{
		smokeInstances.emplace_back(InstanceData{ XMFLOAT3(0, 0, i) });
	}
	const vector<InstanceData>* const smokeInstancesPointer = &smokeInstances;

	
	vector<InstanceData> explosionInstances;
	for (int i = 0; i < 600; i++)
	{
		explosionInstances.emplace_back(InstanceData{ XMFLOAT3(0, 0, i) });
	}
	vector<InstanceData>* const explosionInstancesPointer = &explosionInstances;

	CreateParticles(position, smokeInstancesPointer, explosionInstancesPointer);

	AssignObjects();
}

void GameManager::CreateParticles(const DirectX::XMFLOAT3& position, const std::vector<InstanceData>* const& smokeInstancesPointer, std::vector<InstanceData>* const& explosionInstancesPointer)
{
	GameObject smokeObject(XMFLOAT3(position.x, position.y - 1, position.z), XMFLOAT3(0, 0, 0), XMFLOAT3(.3f, .3f, .3f), "Smoke", 0.0f, 0.0f);
	smokeObject.CreateShape(MeshType::QUAD, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 0.5f, 0.5f), L"smoke.dds", L"", L"", L"SmokeEffect.fx", "SmokeParticle", smokeInstancesPointer, true);
	entities.push_back(smokeObject);
	smoke = &smokeObject;

	GameObject explosionObject(XMFLOAT3(position.x, position.y - 1, position.z), XMFLOAT3(0, 0, 0), XMFLOAT3(.5f, .5f, .5f), "Explosion", 0.0f, 0.0f);
	explosionObject.CreateShape(MeshType::QUAD, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 0.5f, 0.5f), L"fire1.dds", L"", L"", L"ExplosionEffect.fx", "ExplosionParticle", explosionInstancesPointer, true);
	explosionObject.AddLight(XMFLOAT4(0.0f, 3.0f, 0.0f, 1.0f), XMFLOAT4(0.9f, 0.3f, 0.2f, 1.0f), "ExplosionLight");
	entities.push_back(explosionObject);
	explosion = &explosionObject;
	timeSinceExplosion = 0.0f;
}


void GameManager::AssignObjects()
{
	for (auto& entity : entities)
	{
		if (entity.Name() == "Terrain")
		{
			terrain = &entity;
		}
		if (entity.Name() == "Rocket")
		{
			rocket = &entity;
		}
		if (entity.Name() == "Sun")
		{
			sun = &entity;
		}
		if (entity.Name() == "Moon")
		{
			moon = &entity;
		}
		if (entity.Name() == "Explosion")
		{
			explosion = &entity;
		}
		if (entity.Name() == "Launcher")
		{
			launcher = &entity;
		}
		if (entity.Name() == "Smoke")
		{
			smoke = &entity;
		}
	}
}


void GameManager::UpdateRocket(const float& dt)
{
	if (!isEngineOn)
	{
		vector<InstanceData> instances;
		for (int i = 0; i < 200; i++)
		{
			instances.emplace_back(InstanceData{ XMFLOAT3(0, 0, i) });
		}

		//Adds particle system and light to back of rocket
		rocket->CreateShape(MeshType::QUAD, false, XMFLOAT3(0, -4.0f, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1.0f, 1), L"fire1.dds", L"", L"", L"RocketEngine.fx", "RocketEngineFlame", &instances, true);
		rocket->AddLight(XMFLOAT4(0, -4.5f, 0, 1.0f), XMFLOAT4(0.5f, 0.3f, 0.2f, 1.0f), "RocketEngineLight");
		isEngineOn = true;
	}

	
	rocket->MoveEntity(rocket->Up(), timescale, dt * 4);

	if (rocket->Up().y >= -0.999f)
	{
		rocket->RotateEntity(XMFLOAT3(0, 0, XMConvertToRadians(-36)), timescale * 1.2f, dt);
	}

	HandleCamera(dt);
}

void GameManager::HandleCamera(const float& dt)
{
	rocketCam->MoveCamera(rocket->Up(), timescale * rocket->Speed(), dt);
	rocketCam->SetLookAt(rocket->Position());
	rocketNoseCam->SetPosition(XMFLOAT3(rocket->Shapes()[1].WorldPos().x + 0.3f, rocket->Shapes()[1].WorldPos().y + 1.0f, rocket->Shapes()[1].WorldPos().z - 0.2f));
	rocketNoseCam->SetLookAt(rocket->Shapes()[1].WorldPos());
	rocketBodyCam->MoveCamera(rocket->Up(), timescale * rocket->Speed(), dt);
	rocketBodyCam->SetLookAt(rocket->Shapes()[0].WorldPos());
}

void GameManager::RemoveVoxels(const vector<InstanceData> &data, const XMFLOAT3 &conePos)
{
	if (data.size() > 0)
	{
		entities.erase(remove(entities.begin(), entities.end(), *rocket), entities.end());
		rocket = nullptr;
		terrain->RemoveInstancesFromShape("TerrainCube", data);
		isRocketLaunched = false;
		isEngineOn = false;
		SpawnExplosionParticles(conePos);
	}
}

void GameManager::ResetRocketCams()const
{
	rocketCam->SetPosition(XMFLOAT3(0.5f, 8.2f, 1.0f));
	rocketCam->SetLookAt(rocket->Position());
	rocketNoseCam->SetPosition(XMFLOAT3(rocket->Shapes()[1].WorldPos().x + 0.3f, rocket->Shapes()[1].WorldPos().y + 1.0f, rocket->Shapes()[1].WorldPos().z - 0.2f));
	rocketNoseCam->SetLookAt(rocket->Shapes()[1].WorldPos());
	rocketBodyCam->SetPosition(XMFLOAT3(0.5f, 8.2f, 2.5f));
	rocketBodyCam->SetLookAt(rocket->Shapes()[0].WorldPos());
}



GameManager::GameManager()
{

}


GameManager::GameManager(const int& width, const int& height) :
	timescale(1.0f),
	width(width),
	height(height),
	IsExit(false),
	isRocketLaunched(false),
	isEngineOn(false)
{
	InitScene();
}

GameManager::~GameManager()
{
}


void GameManager::InitScene()
{
	canFire = true;
	//Creates instance of keyboard object for input handling
	if (!keyboard) keyboard = std::make_unique<Keyboard>();
	cameras.clear();
	entities.clear();
	entities.reserve(8);
	CreateCameras();
	CreateTerrain();
	CreateLauncherStick();
	CreateSun();
	CreateMoon();
	CreateRocket();
	AssignObjects();
}

void GameManager::CreateMoon()
{
	GameObject moonObject;
	moonObject = GameObject(XMFLOAT3(40, 2.2f, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(10, 10, 10), "Moon", 1.0f, 2.0f);
	moonObject.CreateShape(MeshType::QUAD, false, XMFLOAT3(0, 6.0f, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(1, 2.0f, 1), L"", L"", L"", L"ReflectiveShiny.fx", "Cone", nullptr, false);
	//moonObject.AddShape(MeshType::QUAD, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.05f, 0.05f, 0.05f), L"smoke.dds", L"", L"", L"EffectShader.fx", "MoonCube", nullptr, false);
	moonObject.AddLight(XMFLOAT4(20.0f, 20.0f, 20.0f, 1.0f), XMFLOAT4(0, 0.f, 0.5f, 1.0f), "MoonLight");
	entities.push_back(moonObject);
	moon = &moonObject;
}

void GameManager::CreateSun()
{
	GameObject subObject;
	subObject = GameObject(XMFLOAT3(-20, 2.2f, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(15, 15, 15), "Sun", 1.0f, 2.0f);
	subObject.CreateShape(MeshType::QUAD, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.05f, 0.05f, 0.05f), L"", L"", L"", L"EnviromentEffect.fx", "SunCube", nullptr, false);
	subObject.AddLight(XMFLOAT4(0.0f, 0, 0.0f, 1.0f), XMFLOAT4(0.5f, 0, 0, 1.0f), "SunLight");
	entities.push_back(subObject);
	sun = &subObject;
}

void GameManager::CreateLauncherStick()
{
	GameObject launcherObject;
	launcherObject = GameObject(XMFLOAT3(0.8f, 8.2f, 3.0f), XMFLOAT3(0, 0, 0), XMFLOAT3(0.5f, 1.5f, 0.5f), "Launcher", 1.0f, 2.0f);
	launcherObject.CreateShape(MeshType::CYLINDER, false, XMFLOAT3(0, 0, 0), XMFLOAT3(0, 0, 0), XMFLOAT3(0.2f, 0.5f, 0.2f), L"launcher_diffuse.dds", L"launcher_normal.dds", L"launcher_displacement.dds", L"BumpShader.fx", "LauncherCube", nullptr, false);
	entities.push_back(launcherObject);
	launcher = &launcherObject;
}

void GameManager::ResetScene()
{
	canFire = true;
	isReset = true;
	isRocketLaunched = false;
	isEngineOn = false;
	InitScene();
}

void GameManager::Update(const float& dt)
{
	CheckInput(dt);

	if (sun)
	{
		sun->RotateAroundPoint(XMFLOAT3(10.0f, 3.2f, 0.0f), XMFLOAT3(0, 0, XMConvertToRadians(-5)), timescale, dt);
	}

	if (moon)
	{
		moon->RotateAroundPoint(XMFLOAT3(10.0f, 3.2f, 0.0f), XMFLOAT3(0, 0, XMConvertToRadians(-5)), timescale, dt);
	}

	if (isRocketLaunched && rocket)
	{
		UpdateRocket(dt);
	}

	if (rocket)
	{
		CheckRocketCollision();
	}
	else
	{
		launcher->ResetRotation();
		CreateRocket();
	}

	if (smoke)
	{
		timeSinceExplosion += (dt * timescale);
		if (timeSinceExplosion >= 3.0f && explosion)
		{
			entities.erase(remove(entities.begin(), entities.end(), *explosion), entities.end());
			explosion = nullptr;
			AssignObjects();
		}
		if (timeSinceExplosion >= 3.0f)
		{
			entities.erase(remove(entities.begin(), entities.end(), *smoke), entities.end());
			smoke = nullptr;
			canFire = true;
			AssignObjects();
		}
	}
}

const Camera* const GameManager::ActiveCamera() const
{
	return activeCam;
}

const std::vector<GameObject>& GameManager::Entities() const
{
	return entities;
}

