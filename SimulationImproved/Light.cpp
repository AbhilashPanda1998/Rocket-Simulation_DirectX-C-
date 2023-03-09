#include "Light.h"

using namespace DirectX;
using namespace std;


Light::Light() :
	translation(XMFLOAT4(0, 0, 0, 0)),
	color(XMFLOAT4(0, 0, 0, 0))
{
}


Light::Light(const DirectX::XMFLOAT4X4& entityTransform, const DirectX::XMFLOAT4& lightPos, const DirectX::XMFLOAT4& lightColour, const string& name):
	translation(lightPos),
	color(lightColour),
	name(name)
{
	SetTransform(entityTransform);
}


Light::~Light()
{
}


const DirectX::XMFLOAT4& Light::Position() const
{
	return wolrdpos;
}


const DirectX::XMFLOAT4& Light::Colour() const
{
	return color;
}


const std::string & Light::Name() const
{
	return name;
}


void Light::SetTransform(const DirectX::XMFLOAT4X4 & entityTransform)
{
	//Loads transform matrix into XMMATRIX object for matrix multiplication
	const XMMATRIX entityTransformMatrix = XMLoadFloat4x4(&entityTransform);
	XMMATRIX transformMatrix = XMMatrixIdentity();

	//Sets transform matrix as parent entities transform matrix then mulitplies by the lights translation
	transformMatrix *= XMMatrixTranslationFromVector(XMLoadFloat4(&translation));
	transformMatrix *= entityTransformMatrix;

	//Stores multiplied transform matrix into XMFLOAT4X4
	XMStoreFloat4x4(&transform, transformMatrix);

	//Sets lights world pos
	wolrdpos = XMFLOAT4(transform._41, transform._42, transform._43, 1.0f);
}

void Light::SetColour(const DirectX::XMFLOAT4 & colour)
{
	color = colour;
}
