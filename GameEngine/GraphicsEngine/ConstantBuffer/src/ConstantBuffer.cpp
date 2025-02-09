#include "ConstantBuffer.hpp"
#include "GraphicsEngine.hpp"
#include "DeviceContext.hpp"

ConstantBuffer::ConstantBuffer() : m_buffer(0)
{
}

bool ConstantBuffer::load(void* buffer, UINT size_buffer, IGraphicsEngine* graphics_engine)
{
	if (m_buffer)m_buffer->Release();

	D3D11_BUFFER_DESC buff_desc = {};
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	buff_desc.ByteWidth = size_buffer;
	buff_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA init_data = {};
	init_data.pSysMem = buffer;

	if (FAILED(graphics_engine->getDevice()->CreateBuffer(&buff_desc, &init_data, &m_buffer)))
	{
		return false;
	}

	return true;
}

void ConstantBuffer::update(DeviceContext* context, void* buffer)
{
	context->getDeviceContext()->UpdateSubresource(this->m_buffer, NULL, NULL, buffer, NULL, NULL);
}

bool ConstantBuffer::release()
{
	if (m_buffer)
	{
		m_buffer->Release();
		delete this;
	}
	return true;
}

ConstantBuffer::~ConstantBuffer()
{
}
