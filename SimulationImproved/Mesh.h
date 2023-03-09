#pragma once

#include <string>
#include <vector>
#include <directxmath.h>
#include <Windows.h>
#include <algorithm>
using namespace DirectX;
using namespace std;

/// <summary>
/// Types of geometry for the shape object
/// </summary>
enum class MeshType
{
	CUBE,
	SPHERE,
	CYLINDER,
	CONE,
	QUAD
};

/// <summary>
/// Structure of vertex data to be passed to the shader
/// </summary>
struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT3 Normal;
	XMFLOAT2 TexCoord;
	XMFLOAT3 Tangent;
	XMFLOAT3 BiTangent;
};

/// <summary>
/// Instance data
/// </summary>
struct InstanceData
{
	DirectX::XMFLOAT3 Pos;

	/// <summary>
	/// Comparison operator for InstanceData objects using position vector as comparison value
	/// </summary>
	/// <param name="a">Instance to compare with this instance</param>
	/// <returns>Bool representing if instances are equal or not</returns>
	bool operator==(const InstanceData& a) const
	{
		return (fabs(a.Pos.x - Pos.x) < FLT_EPSILON && fabs(a.Pos.y - Pos.y) < FLT_EPSILON && fabs(a.Pos.z - Pos.z) < FLT_EPSILON);
	}
};

class Mesh
{
private:
	vector<SimpleVertex> vertices;
	vector<WORD> indices;
	vector<InstanceData> mInstanceData;
	XMFLOAT4X4 transform;
    XMFLOAT3 translation;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
	XMFLOAT3 wolrdPos;
	wstring diffuseTexture;
	wstring normalMap;
	wstring displacementMap;
	wstring shader;
	string name;
	MeshType geometryType;
	bool particlesSystem;

	void Cube();
	void Sphere() const;
	void Cylinder();
	void Cone();
	void Quad();

public:
	Mesh();
	Mesh(const MeshType& geometryType, const DirectX::XMFLOAT4X4& entityTransform, const DirectX::XMFLOAT3& translation, const DirectX::XMFLOAT3& rotation, 
		const DirectX::XMFLOAT3& scale, const std::wstring& diffuseTexture, const std::wstring& normalMap, const std::wstring& displacementMap, const std::wstring& shader,
		const std::string& name, const std::vector<InstanceData>* const instanceData, const bool& particleSystem);
	~Mesh();

	const std::vector<SimpleVertex>& Vertices() const;
	const std::vector<WORD>& Indices() const;
	const std::vector<InstanceData>& Instances() const;
	const std::wstring& DiffuseTexture() const;
	const std::wstring& NormalMap() const;
	const std::wstring& DisplacementMap() const;
	const std::wstring& Shader() const;
	const DirectX::XMFLOAT3& WorldPos() const;
	const DirectX::XMFLOAT4X4& Transform() const;
	const MeshType& Geometry() const;
	const std::string& Name() const;
	const bool& ParticleSystem() const;

	void SetTransform(const DirectX::XMFLOAT4X4& entityTransform);
	void RemoveInstances(const std::vector<InstanceData>& instancesToRemove);
};