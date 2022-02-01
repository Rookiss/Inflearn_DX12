#pragma once

class Texture;

// [유니티짱]과 같이 정점으로 이루어진 물체
class Mesh
{
public:
	void Init(const vector<Vertex>& vertexBuffer, const vector<uint32>& indexbuffer);
	void Render();

	void SetTransform(const Transform& t) { _transform = t; }
	void SetTexture(shared_ptr<Texture> tex) { _tex = tex; }

private:
	void CreateVertexBuffer(const vector<Vertex>& buffer);
	void CreateIndexBuffer(const vector<uint32>& buffer);

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {};
	uint32 _vertexCount = 0;

	ComPtr<ID3D12Resource>		_indexBuffer;
	D3D12_INDEX_BUFFER_VIEW		_indexBufferView;
	uint32 _indexCount = 0;

	Transform _transform = {};
	shared_ptr<Texture> _tex = {};
};

