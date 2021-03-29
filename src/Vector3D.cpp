/**
 *
 * @file  Vector.cpp
 * @brief This file contains the implementation of Vector3D class.
 *
 */

#include <cmath>
#include "Vector3D.hpp"


Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0)
{
}

Vector3D::Vector3D(const double& x, const double& y, const double& z) : x(x), y(y), z(z)
{
}

Vector3D Vector3D::operator+(const Vector3D& v)
{
	return Vector3D((x+v.x), (y+v.y), (z+v.z));
}

Vector3D Vector3D::operator-(const Vector3D& v)
{
	return Vector3D((x-v.x), (y-v.y), (z-v.z));
}

Vector3D Vector3D::operator*(const Vector3D& v)
{
	return Vector3D((x*v.x), (y*v.y), (z*v.z));
}

Vector3D Vector3D::operator*(const double& c)
{
	return Vector3D((c*x), (c*y), (c*z));
}

Vector3D Vector3D::crossProduct(const Vector3D& v)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

	a = y * v.z - z * v.y;
	b = z * v.x - x * v.z;
	c = x * v.y - y * v.x;

	return Vector3D(a, b, c);
}

double Vector3D::dotProduct(const Vector3D& v)
{
	return x*v.x + y*v.y + z*v.z;
}

Vector3D Vector3D::normalize()
{
	double norm = 1 / sqrt(dotProduct(*this));
	x = x * norm;
	y = y * norm;
	z = z * norm;

	return *this;
}

Vector3D Vector3D::getInverse()
{
	return Vector3D(-x, -y, -z);
}