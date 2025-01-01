#include "DeviceContext.hpp"
#include "SwapChain.hpp"
#include "VertexBuffer.hpp"
#include <d3d11.h>
#include <iostream>

DeviceContext::DeviceContext(ID3D11DeviceContext* f_deviceContext) : m_deviceContext_p(f_deviceContext)
{
}

void DeviceContext::clearRenderTargetColor(SwapChain* f_swapChain, float r, float g, float b, float alpha)
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
	m_deviceContext_p->OMSetRenderTargets(1, &f_swapChain->m_rtv, NULL);
}

void DeviceContext::setvertexBuffer(VertexBuffer* vertex_buffer)
{
	UINT stride = vertex_buffer->m_size_vertex;
	UINT offset = 0;
	m_deviceContext_p->IASetVertexBuffers(0, 1, &vertex_buffer->m_buffer, &stride, &offset);
	m_deviceContext_p->IASetInputLayout(vertex_buffer->m_layout);
}

void DeviceContext::drawTriangleList(UINT vertex_count, UINT start_vertex_index)
{
	m_deviceContext_p->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	m_deviceContext_p->Draw(vertex_count, start_vertex_index);
}

void DeviceContext::drawTriangleStrip(UINT vertex_count, UINT start_vertex_index)
{
	m_deviceContext_p->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	m_deviceContext_p->Draw(vertex_count, start_vertex_index);
}

void DeviceContext::setViewportSize(UINT width, UINT height)
{
	D3D11_VIEWPORT viewport = {};
	viewport.Width = width;
	viewport.Height = height;
	viewport.MinDepth = 0;
	viewport.MaxDepth = 1;
	m_deviceContext_p->RSSetViewports(1, &viewport);
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