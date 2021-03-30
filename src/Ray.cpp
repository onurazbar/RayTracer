/**
 *
 * @file  Ray.cpp
 * @brief This file contains the implementation of Ray class.
 *
 */

#include "Ray.hpp"


Ray::Ray(const Vector3D& origin, const Vector3D& direction) : origin(origin), direction(direction)
{
}

Vector3D Ray::getOrigin()
{
    return origin;
}

Vector3D Ray::getDirection()
{
    return direction;
}
