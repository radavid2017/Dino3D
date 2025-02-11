#ifndef _VECTOR_3D_HPP_
#define _VECTOR_3D_HPP_

class Vector3D
{
public:
	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}
	Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}
	static Vector3D lerp(const Vector3D& start, const Vector3D& end, float delta);
	~Vector3D() {};
	float x;
	float y;
	float z;
};

#endif // _VECTOR_3D_HPP_
