#pragma once

#include <directxmath.h>
using namespace DirectX;
class Camera
{
private:
	XMFLOAT4X4 view;
	XMFLOAT4X4 proj;
	XMFLOAT4X4 transform;
	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMFLOAT3 forward;
	XMFLOAT3 up;
	XMFLOAT3 right;
	XMFLOAT3 lookatv;
	float speed;
	float rotSpeed;
	bool isMovementAllowed;
	bool isLookAt;

	void SetView();
	void SetProjection(const float& fov, const float& aspectRatio, const float& near, const float& far);
	void SetTransform();
	void SetDirection();

public:
	Camera();
	Camera(const bool& allowMovement, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation, const float& fov, const float& aspectRatio,
		const float& near, const float& far, const float& speed, const float& rotationSpeed);
	Camera(const bool& allowMovement, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation, const DirectX::XMFLOAT3& lookAt, const float& fov,
		const float& aspectRatio, const float& near, const float& far, const float& speed, const float& rotationSpeed);
	~Camera();

	const DirectX::XMFLOAT4X4& View() const;
	const DirectX::XMFLOAT4X4& Projection() const;
	const DirectX::XMFLOAT3& Position() const;
	const DirectX::XMFLOAT3& Up() const;
	const DirectX::XMFLOAT3& Right() const;
	const DirectX::XMFLOAT3& Forward() const;
	const bool& AllowMovement() const;
	const float& Speed() const;
	const float& RotationSpeed() const;

	void MoveCamera(const DirectX::XMFLOAT3& translation, const float& dt);
	void MoveCamera(const DirectX::XMFLOAT3& translation, const float& timeScale, const float& dt);
	void RotateCamera(const DirectX::XMFLOAT3& rotation, const float& dt);
	void SetLookAt(const DirectX::XMFLOAT3& lookAt);
	void SetPosition(const DirectX::XMFLOAT3& position);
	void SetSpeed(const float& speed);
	void SetRotationSpeed(const float& speed);
};