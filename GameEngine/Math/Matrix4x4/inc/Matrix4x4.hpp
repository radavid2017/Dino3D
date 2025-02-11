#ifndef _MATRIX_4X4_HPP_
#define _MATRIX_4X4_HPP_

class Vector3D;

class Matrix4x4
{
public:
	void setIdentity();
	void setTranslation(const Vector3D& f_translation);
	void setScale(const Vector3D& f_scale);
	void operator*=(const Matrix4x4& rhs);
	void setOrthoLH(float f_width, float f_height, float f_near_plane, float f_far_plane);
	float mat[4][4] = {};
};

#endif // !_MATRIX_4X4_HPP_
