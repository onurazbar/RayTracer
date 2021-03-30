/**
 *
 * @file  Triangle.cpp
 * @brief This file contains the implementation of Triangle class.
 *
 */

#include "Triangle.hpp"


Triangle::Triangle(const Vector3D& color, const Vector3D& p1, const Vector3D& p2, const Vector3D& p3) 
                                                  : Object(color), point1(p1), point2(p2), point3(p3)
{
}

Triangle::~Triangle()
{
}

bool Triangle::checkIntersection(double& t, Ray& ray)
{
    // Preferred Moller-Trumbore algorithm with barycentric
    // coordinates instead of geotmetric solution
    Vector3D edge1 = point2 - point1;
    Vector3D edge2 = point3 - point1;

    Vector3D vector1 = ray.getDirection().crossProduct(edge2);

    double determinant = edge1.dotProduct(vector1);

    if (determinant < 0.00000001)
    {
        // Consider triangle and ray are parallel and no intersection
        return false;
    }

    Vector3D vector2 = ray.getOrigin() - point1;
    double u = vector2.dotProduct(vector1) / determinant;

    if ((u < 0.0) || (u > 1.0))
    {
        return false;
    }

    Vector3D vector3 = vector2.crossProduct(edge1);
    double v = ray.getDirection().dotProduct(vector3) / determinant;

    if ((v < 0.0) || (v > 1.0))
    {
        return false;
    }

    t = edge2.dotProduct(vector3) / determinant;

    return true;
}

Vector3D Triangle::getSurfaceNormal(Vector3D& point)
{
    Vector3D normal = (point2 - point1).crossProduct(point3 - point1);
    normal.normalize();
    return normal;
}
