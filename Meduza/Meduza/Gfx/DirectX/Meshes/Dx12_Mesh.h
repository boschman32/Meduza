#pragma once

#include "../../Common/Mesh.h"

class Dx12_Device;
class Dx12_CommandList;

class Dx12_Mesh : public Mesh {

public:
	Dx12_Mesh(MeshType);

	void InitilizeMesh(const Dx12_Device&, Dx12_CommandList*);

	D3D12_VERTEX_BUFFER_VIEW VertexBufferView()const;

	D3D12_INDEX_BUFFER_VIEW IndexBufferView()const;

	void DisposeUploaders();

	int GetIndexCount();

protected:
	std::vector<Vertex> m_vertices;
	std::vector<std::uint16_t> m_indices;

	DXGI_FORMAT m_indexFormat = DXGI_FORMAT_R16_UINT;

	Microsoft::WRL::ComPtr<ID3DBlob> m_vertexBufferCPU = nullptr;
	Microsoft::WRL::ComPtr<ID3DBlob> m_indexBufferCPU = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> m_vertexBufferGPU = nullptr;
	Microsoft::WRL::ComPtr<ID3D12Resource> m_indexBufferGPU = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> m_vertexBufferUploader = nullptr;
	Microsoft::WRL::ComPtr<ID3D12Resource> m_indexBufferUploader = nullptr;

	std::unordered_map<int, SubmeshGeometry> m_drawArgs;
};