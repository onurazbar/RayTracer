/**
 *
 * @file  Sphere.cpp
 * @brief This file contains the implementation of Sphere class.
 *
 */

#include <cmath>
#include "Sphere.hpp"


Sphere::Sphere(const Vector3D& color, const Vector3D& center, const double& radius) 
									: Object(color), center(center), radius(radius)
{
}

Sphere::~Sphere()
{
}

Vector3D Sphere::getCenter()
{
	return center;
}

void Sphere::setCenter(const Vector3D& center)
{
	this->center = center;
}

double Sphere::getRadius()
{
	return radius;
}

void Sphere::setRadius(const double& radius)
{
	this->radius = radius;
}

bool Sphere::checkIntersection(double& t, Ray& ray)
{
	// Calculate intersection of ray and plane via geometric solution
	Vector3D origin = ray.getOrigin();
	Vector3D direction = ray.getDirection();
	Vector3D oc = center - origin;
	double tm = oc.dotProduct(direction);

	if (tm < 0.0)
	{
		return false;
	}

	double h_square = oc.dotProduct(oc) - tm*tm;

	if (h_square > (radius * radius))
	{
		// Consider point is outside the sphere
		return false;
	}

	double t0m = sqrt((radius * radius) - h_square);
	double t0 = tm - t0m;
	double t1 = tm + t0m;

	if (t0 > t1)
	{
		double temp = t1;
		t1 = t0;
		t0 = temp;
	}

	t = t0;

	if (t0 < 0.0)
	{
		if (t1 < 0.0)
		{
			return false;
		}

		t = t1;
	}
	return true;
}

Vector3D Sphere::getSurfaceNormal(Vector3D& point)
{
	Vector3D normal = point - center;
	normal.normalize();
	return normal;
}