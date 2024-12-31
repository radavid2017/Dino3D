#ifndef _VERTEX_BUFFER_HPP_
#define _VERTEX_BUFFER_HPP_

#include <d3d11.h>

class DeviceContext;
class IGraphicsEngine; // Forward declaration for IGraphicsEngine

class VertexBuffer
{
public:
    VertexBuffer();
    bool load(void* list_vertices, UINT size_vertex, UINT size_list, void* shader_byte_code, UINT size_byte_shader, IGraphicsEngine* graphics_engine);
	UINT getSizeVertexList();
	bool release();
    ~VertexBuffer();
private:
	UINT m_size_vertex;
	UINT m_size_list;
	ID3D11Buffer* m_buffer;
	ID3D11InputLayout* m_layout;
	friend class DeviceContext;
};

#endif // _VERTEX_BUFFER_HPP_