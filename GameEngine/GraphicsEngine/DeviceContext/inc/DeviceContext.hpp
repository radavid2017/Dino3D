#ifndef _DEVICE_CONTEXT_HPP_
#define _DEVICE_CONTEXT_HPP_

#include <d3d11.h>
class SwapChain;
class VertexBuffer;
class VertexShader;
class PixelShader;

class DeviceContext
{
public:
    DeviceContext(ID3D11DeviceContext* f_deviceContext);
    void clearRenderTargetColor(SwapChain* f_swapChain, float r, float g, float b, float alpha);
	void setvertexBuffer(VertexBuffer* vertex_buffer);
	void drawTriangleList(UINT vertex_count, UINT start_vertex_index);
	void drawTriangleStrip(UINT vertex_count, UINT start_vertex_index);
	
    void setViewportSize(UINT width, UINT height);

	void setVertexShader(VertexShader* f_vertex_shader);
	void setPixelShader(PixelShader* f_pixel_shader);

    bool release();
    ~DeviceContext();
private:
    ID3D11DeviceContext* m_deviceContext_p;
};

#endif // _DEVICE_CONTEXT_HPP_