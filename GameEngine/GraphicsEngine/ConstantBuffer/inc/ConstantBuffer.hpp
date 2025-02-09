#ifndef _CONSTANT_BUFFER_HPP_
#define _CONSTANT_BUFFER_HPP_

#include <d3d11.h>

class IGraphicsEngine; // Forward declaration for IGraphicsEngine
class DeviceContext;

class ConstantBuffer
{
public:
	ConstantBuffer();
	bool load(void* buffer, UINT size_buffer, IGraphicsEngine* graphics_engine);
	void update(DeviceContext* context, void* buffer);
	bool release();
	~ConstantBuffer();
private:
	ID3D11Buffer* m_buffer;
	friend class DeviceContext;
};

#endif // !_CONSTANT_BUFFER_HPP_
