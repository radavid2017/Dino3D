#ifndef _VERTEX_SHADER_HPP_
#define _VERTEX_SHADER_HPP_

#include <d3d11.h>

class IGraphicsEngine; // Forward declaration for IGraphicsEngine
class DeviceContext;

class VertexShader
{
public:
	VertexShader();
	void release();
	~VertexShader();
private:
	bool init(const void* f_shader_byte_code, size_t f_byte_code_size, IGraphicsEngine* f_graphicsEngine);
	ID3D11VertexShader* m_vs;
	friend class GraphicsEngine;
	friend class DeviceContext;
};

#endif // !_VERTEX_SHADER_HPP_
