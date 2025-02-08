#include "PixelShader.hpp"
#include "GraphicsEngine.hpp"
#include <iostream>

PixelShader::PixelShader()
{
}

void PixelShader::release()
{
	if (m_ps)
	{
		m_ps->Release();
		delete this;
	}
}

bool PixelShader::init(const void* f_shader_byte_code, size_t f_byte_code_size, IGraphicsEngine* f_graphicsEngine)
{
	if (!SUCCEEDED(f_graphicsEngine->getDevice()->CreatePixelShader(f_shader_byte_code, f_byte_code_size, nullptr, &m_ps)))
	{
		std::cout << "aici\n";
		return false;
	}
	return true;
}

PixelShader::~PixelShader()
{
}