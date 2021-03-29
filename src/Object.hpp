/**
 *
 * @file  Object.hpp
 * @brief This file defines Object class.
 *
 */

#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "Ray.hpp"


class Object
{
protected:

	/**
	* @brief Color of the object.
	*/
	Vector3D color;

public:

	/**
	* @brief Parameterized constructor
	*/
	Object(const Vector3D& color);

	/**
	* @brief Virtual destructor.
	*/
	virtual ~Object();

	/**
	* @brief Returns color of the object.
	* @return color attribute.
	*/
	Vector3D getColor();

	/**
	* @brief Sets color of the object.
	* @param color to be set.
	*/
	void setColor(const Vector3D& color);

	/**
	* @brief Checks whether the ray intersects with the object or not.
	* @param t intersection point.
	* @param ray ray that will be checked for intersection.
	* @return true if there is an intersection, false otherwise.
	*/
	virtual bool checkIntersection(double& t, Ray& ray) = 0;

	/**
	* @brief Gets the normal vector of the surface.
	* @param point the point that normal pass through.
	* @return true if there is an intersection, false otherwise.
	*/
	virtual Vector3D getSurfaceNormal(Vector3D& point) = 0;
};

#endif /* OBJECT_HPP_INCLUDED */