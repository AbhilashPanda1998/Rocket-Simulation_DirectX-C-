#pragma once

#include <directxmath.h>
#include <string>
using namespace DirectX;
using namespace std;

class Light
{
private:
	XMFLOAT4X4 transform;
	XMFLOAT4 translation;
	XMFLOAT4 wolrdpos;
	XMFLOAT4 color;
	string name;

public:
	Light();
	Light(const XMFLOAT4X4& entityTransform, const XMFLOAT4& lightPos, const XMFLOAT4& lightColour, const string& name);
	~Light();

	const XMFLOAT4& Position() const;
	const XMFLOAT4& Colour() const;
	const string& Name() const;

	void SetTransform(const XMFLOAT4X4& entityTransform);
	void SetColour(const XMFLOAT4& colour);
};