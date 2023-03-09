#pragma once

#include "Mesh.h"
#include "Light.h"
#include <string>
#include <vector>
#include <directxmath.h>

using namespace DirectX;
class GameObject
{
private:
	std::vector<Mesh> shapes;
	std::vector<Light> lights;

	XMFLOAT4X4 transform;
	XMFLOAT3 mTranslation;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
	XMFLOAT3 forward;
	XMFLOAT3 up;
	XMFLOAT3 right;

	std::string name;
	float mSpeed;
	float rotspeed;

	void UpdateChildren();
	void SetTransform();
	void SetDirection();

public:
	GameObject();
	GameObject(const DirectX::XMFLOAT3& translation, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& scale, const std::string& name, const float& speed, const float& rotationSpeed);
	~GameObject();

	const std::vector<Mesh>& Shapes() const;
	const std::vector<Light>& Lights() const;
	const XMFLOAT3& Up() const;
	const XMFLOAT3& Right() const;
	const XMFLOAT3& Forward() const;
	const XMFLOAT3& Position() const;
	const XMFLOAT4X4& Transform() const;
	const std::string& Name() const;
	const float& Speed() const;
	const float& RotationSpeed() const;

	void CreateShape(const MeshType& geometryType, const bool& skyBox, const DirectX::XMFLOAT3& translation, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& scale, 
		const std::wstring& diffuseMap, const std::wstring& normalMap, const std::wstring& displacementMap, const std::wstring& shader, const std::string &name, 
		const std::vector<InstanceData>* const instanceData, const bool& particleSystem);
	void AddLight(const DirectX::XMFLOAT4& translation, const DirectX::XMFLOAT4& colour, const std::string& name);
	void MoveEntity(const DirectX::XMFLOAT3& translation, const float& timeScale, const float& dt);
	void RotateEntity(const DirectX::XMFLOAT3& rotation, const float& timeScale, const float& dt);
	void RotateAroundPoint(const DirectX::XMFLOAT3& point, const DirectX::XMFLOAT3& rotation, const float& timeScale, const float& dt);
	void SetPosition(const DirectX::XMFLOAT3& position);
	void ResetRotation();
	void SetSpeed(const float& speed);
	void SetRotationSpeed(const float& speed);
	void RemoveInstancesFromShape(const std::string& name, const std::vector<InstanceData>& instances);
};

bool operator==(const GameObject& a, const GameObject& b);
