#include "Vector3D.hpp"

Vector3D Vector3D::lerp(const Vector3D& start, const Vector3D& end, float delta)
{
	Vector3D v;
	v.x = start.x * (1.0f - delta) + end.x * (delta);
	v.y = start.y * (1.0f - delta) + end.y * (delta);
	v.z = start.z * (1.0f - delta) + end.z * (delta);
	return v;
}