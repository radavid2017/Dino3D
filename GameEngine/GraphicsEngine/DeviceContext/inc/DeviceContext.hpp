#ifndef _DEVICE_CONTEXT_HPP_
#define _DEVICE_CONTEXT_HPP_

#include <d3d11.h>
class SwapChain;

class DeviceContext
{
public:
    DeviceContext(ID3D11DeviceContext* f_deviceContext);
    bool clearRenderTargetColor(SwapChain* f_swapChain, float r, float g, float b, float alpha);
    bool release();
    ~DeviceContext();
private:
    ID3D11DeviceContext* m_deviceContext_p;
};

#endif // _DEVICE_CONTEXT_HPP_