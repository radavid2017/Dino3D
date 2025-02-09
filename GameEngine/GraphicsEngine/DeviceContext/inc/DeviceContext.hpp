#ifndef _DEVICE_CONTEXT_HPP_
#define _DEVICE_CONTEXT_HPP_

#include "IDeviceContext.hpp"
#include <d3d11.h>
class SwapChain;
class VertexBuffer;
class VertexShader;
class PixelShader;
class ConstantBuffer;

class DeviceContext : public IDeviceContext
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

	void setConstantBuffer(VertexShader* f_vertex_shader, ConstantBuffer* f_constant_buffer);
	void setConstantBuffer(PixelShader* f_pixel_shader, ConstantBuffer* f_constant_buffer);	

	/// <summary>
	/// Retrieves the device context associated with the graphics engine.
	/// The device context is used to issue rendering commands to the GPU.
	/// </summary>
	/// <returns> A pointer to the ID3D11DeviceContext instance </returns>
	ID3D11DeviceContext* getDeviceContext() override { return m_deviceContext_p; }

    bool release();
    ~DeviceContext();
private:
    ID3D11DeviceContext* m_deviceContext_p;
	friend class ConstantBuffer;
};

#endif // _DEVICE_CONTEXT_HPP_