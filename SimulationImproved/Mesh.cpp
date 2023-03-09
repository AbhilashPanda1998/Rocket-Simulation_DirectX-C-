#include "Mesh.h"

using namespace std;
using namespace DirectX;

/// <summary>
/// Sets the vertices and indices of the shape to that of a cube
/// </summary>
void Mesh::Cube()
{
	//24 vertices
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });

	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });

	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, -1.0f) });

	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 0.0f, 1.0f) });

	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, -1.0f), XMFLOAT3(0.0f, 0.0f, -1.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(-1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f) });

	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });

	//36 indices
	indices.push_back(3);	indices.push_back(1);	indices.push_back(0);
	indices.push_back(2);	indices.push_back(1);	indices.push_back(3);
	indices.push_back(6);	indices.push_back(4);	indices.push_back(5);
	indices.push_back(7);	indices.push_back(4);	indices.push_back(6);
	indices.push_back(11);	indices.push_back(9);	indices.push_back(8);
	indices.push_back(10);	indices.push_back(9);	indices.push_back(11);
	indices.push_back(14);	indices.push_back(12);	indices.push_back(13);
	indices.push_back(15);	indices.push_back(12);	indices.push_back(14);
	indices.push_back(19);	indices.push_back(17);	indices.push_back(16);
	indices.push_back(18);	indices.push_back(17);	indices.push_back(19);
	indices.push_back(22);	indices.push_back(20);	indices.push_back(21);
	indices.push_back(23);	indices.push_back(20);	indices.push_back(22);
}

void Mesh::Sphere() const
{
}


void Mesh::Cylinder()
{
	const auto pointsOnCircle = 30;

	//Sides
	for (auto i = 0; i < pointsOnCircle; i++)
	{
		const auto fraction = static_cast<float>(i) / (pointsOnCircle - 1);
		const auto theta = 2 * XM_PI * fraction;

		//Tube top
		XMFLOAT3 normal(sin(theta), 0.0f, cos(theta));
		XMFLOAT3 tangent(0, 1.0f, 0);
		XMFLOAT3 biTangent;
		XMStoreFloat3(&biTangent, XMVector3Cross(XMLoadFloat3(&normal), XMLoadFloat3(&tangent)));
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), 1.0f, cos(theta)), normal, XMFLOAT2(fraction, 1.0f), tangent, biTangent });	

		//Tube bottom
		tangent.y = -1.0f;
		XMStoreFloat3(&biTangent, XMVector3Cross(XMLoadFloat3(&normal), XMLoadFloat3(&tangent)));
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), -1.0f, cos(theta)), normal, XMFLOAT2(fraction, 0.0f), tangent, biTangent });
	}

	//Cap top centre
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(1.0f, 0, 0), XMFLOAT3(0, 0, 1.0f) });

	//Cap bottom centre
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(-1.0f, 0, 0), XMFLOAT3(0, 0, -1.0f) });

	for (int i = 0; i < pointsOnCircle; i++)
	{
		const float fraction = static_cast<float>(i) / (pointsOnCircle - 1);
		const float theta = 2 * XM_PI * fraction;

		//Cap top
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), 1.0f, cos(theta)), XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT2(sin(theta) + 1 / 2, cos(theta) + 1 / 2), XMFLOAT3(1.0f, 0, 0), XMFLOAT3(0, 0, 1.0f) });

		//Cap bottom
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), -1.0f, cos(theta)), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(sin(theta) + 1 / 2, cos(theta) + 1 / 2), XMFLOAT3(-1.0f, 0, 0), XMFLOAT3(0, 0, -1.0f) });
	}

	for (int i = 0; i < (pointsOnCircle * 2); i += 2)
	{
		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);
		indices.push_back(i + 1);
		indices.push_back(i + 3);
		indices.push_back(i + 2);
	}


	for (int i = 2; (i < pointsOnCircle * 2); i += 2)
	{
		//Top cap
		indices.push_back(pointsOnCircle * 2);
		indices.push_back((pointsOnCircle * 2) + i);
		indices.push_back((pointsOnCircle * 2) + (i + 2));

		//Bottom cap
		indices.push_back(pointsOnCircle * 2 + 1);
		indices.push_back((pointsOnCircle * 2 + 1) + (i + 2));
		indices.push_back((pointsOnCircle * 2 + 1) + i);
	}
}

void Mesh::Cone()
{
	const int pointsOnCircle = 600;

	//Calculate vector of side of cone
	const float radius = 1;
	const float height = 2;
	const float sideLength = sqrtf(radius * radius + height * height);
	const float coneX = radius / sideLength;
	const float coneY = -height / sideLength;

	//Cone sides
	for (int i = 0; i < pointsOnCircle; i++)
	{
		const float fraction = static_cast<float>(i) / (pointsOnCircle - 1);
		const float theta = 2 * XM_PI * fraction;

		//Top point
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(-coneY * sin(theta), coneX, -coneY * cos(theta)), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(1.0f, 0, 0), XMFLOAT3(0, 0, 1.0f) });

		//Bottom circle
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), -1.0f, cos(theta)), XMFLOAT3(-coneY * sin(theta), coneX, -coneY * cos(theta)), XMFLOAT2(sin(theta) + 1 / 2, cos(theta) + 1 / 2), XMFLOAT3(-1.0f, 0, 0), XMFLOAT3(0, 0, -1.0f) });
	}

	//Bottom centre
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(-1.0f, 0, 0), XMFLOAT3(0, 0, -1.0f) });

	//Cone Bottom
	for (int i = 0; i < pointsOnCircle; i++)
	{
		const float fraction = static_cast<float>(i) / (pointsOnCircle - 1);
		const float theta = 2 * XM_PI * fraction;

		//Bottom circle
		vertices.emplace_back(SimpleVertex{ XMFLOAT3(sin(theta), -1.0f, cos(theta)), XMFLOAT3(0.0f, -1.0f, 0.0f), XMFLOAT2(sin(theta) + 1 / 2, cos(theta) + 1 / 2), XMFLOAT3(-1.0f, 0, 0), XMFLOAT3(0, 0, -1.0f) });
	}

	//Triangles of cone sides
	for (int i = 0; i < (pointsOnCircle * 2) - 2; i += 2)
	{
		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 3);
	}
	indices.push_back(58);
	indices.push_back(59);
	indices.push_back(1);

	//Triangles of bottom circle
	for (int i = 1; (i < pointsOnCircle); i++)
	{
		//Bottom cap
		indices.push_back(pointsOnCircle * 2);
		indices.push_back((pointsOnCircle * 2) + (i + 1));
		indices.push_back((pointsOnCircle * 2) + i);
	}
}

void Mesh::Quad()
{
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, -1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 1.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(0.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	vertices.emplace_back(SimpleVertex{ XMFLOAT3(-1.0f, 1.0f, 1.0f), XMFLOAT3(0.0f, 0.0f, 1.0f), XMFLOAT2(1.0f, 0.0f), XMFLOAT3(1.0f, 0.0f, 0.0f), XMFLOAT3(0.0f, 1.0f, 0.0f) });
	indices.push_back(3);
	indices.push_back(1);	
	indices.push_back(0);
	indices.push_back(2);	
	indices.push_back(1);	
	indices.push_back(3);
}

Mesh::Mesh() :
	geometryType(MeshType::CUBE),
	particlesSystem(0)
{
}

Mesh::Mesh(const MeshType& geometryType, const XMFLOAT4X4& entityTransform, const XMFLOAT3& translation, const DirectX::XMFLOAT3& rotation,
	const XMFLOAT3& scale, const std::wstring& diffuseTexture, const std::wstring& normalMap, const std::wstring& displacementMap, const wstring& shader, 
	const string& name, const std::vector<InstanceData>* const instanceData, const bool& particleSystem) :
	translation(translation),
	rotation(rotation),
	scale(scale),
	diffuseTexture(diffuseTexture),
	normalMap(normalMap),
	displacementMap(displacementMap),
	shader(shader),
	name(name),
	geometryType(geometryType),
	particlesSystem(particleSystem)
{
	//Sets transform of shape relative to parent entities transform
	SetTransform(entityTransform);

	//Checks instance data pointer isn't null then sets instance data of shape
	if (instanceData)
	{
		mInstanceData = *instanceData;
	}

	//Sets vertices and indices of shape based on geometry type eg. cube
	switch (geometryType)
	{
	//Sets vertices and indices of the shape to those of a cube
	case MeshType::CUBE: Cube();
		break;
	//Sets vertices and indices of the shape to those of a sphere
	case MeshType::SPHERE: Sphere();
		break;
	//Sets vertices and indices of the shape to those of a cylinder
	case MeshType::CYLINDER: Cylinder();
		break;
	//Sets vertices and indices of the shape to those of a cone
	case MeshType::CONE: Cone();
		break;
	//Sets vertices and indices of the shape to those of a quad
	case MeshType::QUAD: Quad();
		break;
	}
}

Mesh::~Mesh()
{
}

const vector<SimpleVertex>& Mesh::Vertices() const
{
	return vertices;
}

const vector<WORD>& Mesh::Indices() const
{
	return indices;
}

const std::vector<InstanceData>& Mesh::Instances() const
{
	return mInstanceData;
}

const std::wstring& Mesh::DiffuseTexture() const
{
	return diffuseTexture;
}

const std::wstring& Mesh::NormalMap() const
{
	return normalMap;
}

const std::wstring& Mesh::DisplacementMap() const
{
	return displacementMap;
}

const wstring& Mesh::Shader() const
{
	return shader;
}

const DirectX::XMFLOAT3& Mesh::WorldPos() const
{
	return wolrdPos;
}

const XMFLOAT4X4& Mesh::Transform() const
{
	return transform;
}

const MeshType& Mesh::Geometry() const
{
	return geometryType;
}

const std::string& Mesh::Name() const
{
	return name;
}

const bool& Mesh::ParticleSystem() const
{
	return particlesSystem;
}

void Mesh::SetTransform(const XMFLOAT4X4& entityTransform)
{
	//Loads transform matrix into XMMATRIX object for matrix multiplication
	const XMMATRIX entityTransformMatrix = XMLoadFloat4x4(&entityTransform);
	XMMATRIX transformMatrix = XMMatrixIdentity();

	//Sets transform matrix as parent entities transform matrix then mulitplies by the shapes translation, rotation and scale
	transformMatrix *= XMMatrixScaling(scale.x, scale.y, scale.z);
	transformMatrix *= XMMatrixRotationX(rotation.x) * XMMatrixRotationY(rotation.y) * XMMatrixRotationZ(rotation.z);
	transformMatrix *= XMMatrixTranslationFromVector(XMLoadFloat3(&translation));
	transformMatrix *= entityTransformMatrix;

	//Stores multiplied transform matrix into XMFLOAT4X4
	XMStoreFloat4x4(&transform, transformMatrix);

	//Sets world pos of shape
	wolrdPos = XMFLOAT3(transform._41, transform._42, transform._43);
}

void Mesh::RemoveInstances(const std::vector<InstanceData>& instancesToRemove)
{
	for (auto& instance : instancesToRemove)
	{
		mInstanceData.erase(remove(mInstanceData.begin(), mInstanceData.end(), instance), mInstanceData.end());
	}
}
