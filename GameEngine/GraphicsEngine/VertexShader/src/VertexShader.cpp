#include "VertexShader.hpp"
#include "GraphicsEngine.hpp"
#include <iostream>

VertexShader::VertexShader()
{
}

void VertexShader::release()
{
	if (m_vs)
	{
		m_vs->Release();
		delete this;
	}
}

bool VertexShader::init(const void* f_shader_byte_code, size_t f_byte_code_size, IGraphicsEngine* f_graphicsEngine)
{
	if (!SUCCEEDED(f_graphicsEngine->getDevice()->CreateVertexShader(f_shader_byte_code, f_byte_code_size, nullptr, &m_vs)))
	{
		std::cout << "aici\n";
		return false;
	}
	return true;
}

VertexShader::~VertexShader()
{
}