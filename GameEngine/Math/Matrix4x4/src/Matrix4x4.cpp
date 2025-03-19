#include "Matrix4x4.hpp"
#include "Vector3D.hpp"
#include <memory>

void Matrix4x4::setIdentity()
{
	::memset(mat, 0, sizeof(float) * 16);
	mat[0][0] = 1.0f;
	mat[1][1] = 1.0f;
	mat[2][2] = 1.0f;
	mat[3][3] = 1.0f;
}

void Matrix4x4::setTranslation(const Vector3D& f_translation)
{
	setIdentity();
	mat[3][0] = f_translation.x;
	mat[3][1] = f_translation.y;
	mat[3][2] = f_translation.z;
}

void Matrix4x4::setScale(const Vector3D& f_scale)
{
	setIdentity();
	mat[0][0] = f_scale.x;
	mat[1][1] = f_scale.y;
	mat[2][2] = f_scale.z;
}

void Matrix4x4::setRotationX(float f_x)
{
	mat[1][1] = cos(f_x);
	mat[1][2] = sin(f_x);
	mat[2][1] = -sin(f_x);
	mat[2][2] = cos(f_x);
}

void Matrix4x4::setRotationY(float f_y)
{
	mat[0][0] = cos(f_y);
	mat[0][2] = -sin(f_y);
	mat[2][0] = sin(f_y);
	mat[2][2] = cos(f_y);
}

void Matrix4x4::setRotationZ(float f_z)
{
	mat[0][0] = cos(f_z);
	mat[0][1] = sin(f_z);
	mat[1][0] = -sin(f_z);
	mat[1][1] = cos(f_z);
}

void Matrix4x4::operator*=(const Matrix4x4& rhs)
{
	Matrix4x4 out;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out.mat[i][j] =
				mat[i][0] * rhs.mat[0][j] + mat[i][1] * rhs.mat[1][j] 
			  + mat[i][2] * rhs.mat[2][j] + mat[i][3] * rhs.mat[3][j];
		}
	}
	::memcpy(mat, out.mat, sizeof(float) * 16);
}

void Matrix4x4::setOrthoLH(float f_width, float f_height, float f_near_plane, float f_far_plane)
{
	setIdentity();
	mat[0][0] = 2.0f / f_width;
	mat[1][1] = 2.0f / f_height;
	mat[2][2] = 1.0f / (f_far_plane - f_near_plane);
	mat[3][2] = -f_near_plane / (f_far_plane - f_near_plane);
	mat[2][3] = 0.0f;
	mat[3][3] = 1.0f;
}
