/**
 *
 * @file  Plane.hpp
 * @brief This file defines Plane class.
 *
 */

#ifndef PLANE_HPP_INCLUDED
#define PLANE_HPP_INCLUDED

#include "Object.hpp"


class Plane : public Object
{
private:

    /**
    * @brief Point on the plane.
    */
    Vector3D point;

    /**
    * @brief Normal of the plane.
    */
    Vector3D normal;

public:

    /**
    * @brief Parameterized constructor
    */
    Plane(const Vector3D& color, const Vector3D& point, const Vector3D& normal);

    /**
    * @brief Destructor.
    */
    ~Plane();

    /**
    * @brief Returns plane point.
    * @return point attribute.
    */
    Vector3D getPlanePoint();

    /**
    * @brief Checks whether the ray intersects with the plane or not.
    * @param t intersection point.
    * @param ray ray that will be checked for intersection.
    * @return true if there is an intersection, false otherwise.
    */
    bool checkIntersection(double& t, Ray& ray);

    /**
    * @brief Gets the normal vector of the plane.
    * @param point the point that normal pass through.
    * @return true if there is an intersection, false otherwise.
    */
    Vector3D getSurfaceNormal(Vector3D& point);
};

#endif /* PLANE_HPP_INCLUDED */
