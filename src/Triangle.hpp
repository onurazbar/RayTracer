/**
 *
 * @file  Triangle.hpp
 * @brief This file defines Triangle class.
 *
 */

#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include "Object.hpp"


class Triangle : public Object
{
private:

	/**
	* @brief First point on the triangle.
	*/
	Vector3D point1;

	/**
	* @brief Second point on the triangle.
	*/
	Vector3D point2;

	/**
	* @brief Third point on the triangle.
	*/
	Vector3D point3;

public:

	/**
	* @brief Parameterized constructor
	*/
	Triangle(const Vector3D& color, const Vector3D& p1, const Vector3D& p2, const Vector3D& p3);

	/**
	* @brief Destructor.
	*/
	~Triangle();

	/**
	* @brief Checks whether the ray intersects with the triangle or not.
	* @param t intersection point.
	* @param ray ray that will be checked for intersection.
	* @return true if there is an intersection, false otherwise.
	*/
	bool checkIntersection(double& t, Ray& ray);

	/**
	* @brief Gets the normal vector of the sphere.
	* @param point the point that normal pass through.
	* @return true if there is an intersection, false otherwise.
	*/
	Vector3D getSurfaceNormal(Vector3D& point);
};

#endif /* TRIANGLE_HPP_INCLUDED */