/**
 *
 * @file  Plane.cpp
 * @brief This file contains the implementation of Plane class.
 *
 */

#include "Plane.hpp"


Plane::Plane(const Vector3D& color, const Vector3D& point, const Vector3D& normal) 
									 : Object(color), point(point), normal(normal)
{
}

Plane::~Plane()
{
}

Vector3D Plane::getPlanePoint()
{
	return point;
}

bool Plane::checkIntersection(double& t, Ray& ray)
{
	// Calculate intersection of ray and plane via geometric solution
	double product = normal.dotProduct(ray.getDirection());

	if (product < 0.00000001)
	{
		// Consider plane and ray are parallel and no intersection
		return false;
	}
	else
	{
		t = normal.dotProduct((point - ray.getOrigin())) / normal.dotProduct(ray.getDirection());
		return true;
	}
}

Vector3D Plane::getSurfaceNormal(Vector3D& point)
{
	normal.normalize();
	return normal;
}