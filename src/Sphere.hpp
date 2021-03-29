/**
 *
 * @file  Sphere.hpp
 * @brief This file defines Sphere class.
 *
 */

#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED

#include "Object.hpp"


class Sphere : public Object
{
private:

	/**
	* @brief Center of the sphere.
	*/
	Vector3D center;

	/**
	* @brief Radius of the sphere.
	*/
	double radius;

public:

	/**
	* @brief Parameterized constructor
	*/
	Sphere(const Vector3D& color, const Vector3D& center, const double& radius);

	/**
	* @brief Destructor.
	*/
	~Sphere();

	/**
	* @brief Returns center of the sphere.
	* @return center attribute.
	*/
	Vector3D getCenter();

	/**
	* @brief Sets center of the sphere.
	* @param center to be set.
	*/
	void setCenter(const Vector3D& center);

	/**
	* @brief Returns radius of the sphere.
	* @return radius attribute.
	*/
	double getRadius();

	/**
	* @brief Sets radius of the sphere.
	* @param radius to be set.
	*/
	void setRadius(const double& radius);

	/**
	* @brief Checks whether the ray intersects with the sphere or not.
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

#endif /* SPHERE_HPP_INCLUDED */