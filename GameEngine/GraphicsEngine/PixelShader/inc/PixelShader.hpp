#ifndef _PIXEL_SHADER_HPP
#define _PIXEL_SHADER_HPP

#include <d3d11.h>

class IGraphicsEngine; // Forward declaration for IGraphicsEngine	
class DeviceContext;

class PixelShader
{
public:
	PixelShader();
	void release();
	~PixelShader();
private:
	bool init(const void* f_shader_byte_code, size_t f_byte_code_size, IGraphicsEngine* f_graphicsEngine);
	ID3D11PixelShader* m_ps;
	friend class GraphicsEngine;
	friend class DeviceContext;
};

#endif // !_PIXEL_SHADER_HPP