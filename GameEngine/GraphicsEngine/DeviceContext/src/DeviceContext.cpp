#include "DeviceContext.hpp"
#include "SwapChain.hpp"
#include <d3d11.h>
#include <iostream>

DeviceContext::DeviceContext(ID3D11DeviceContext* f_deviceContext) : m_deviceContext_p(f_deviceContext)
{
}

bool DeviceContext::clearRenderTargetColor(SwapChain* f_swapChain, float r, float g, float b, float alpha)
{
	if (f_swapChain == nullptr)
	{
		std::cout << "e null swap chain-ul\n";
	}
	FLOAT clearColor[] = { r, g, b, alpha };
	if (f_swapChain->m_rtv == nullptr)
	{
		std::cout << "e null rtv-ul\n";
	}
	m_deviceContext_p->ClearRenderTargetView(f_swapChain->m_rtv, clearColor);
	return true;
}

bool DeviceContext::release()
{
	m_deviceContext_p->Release();
	delete this;
	return true;
}

DeviceContext::~DeviceContext()
{
}
