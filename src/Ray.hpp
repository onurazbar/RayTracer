/**
 *
 * @file  Ray.hpp
 * @brief This file defines Ray class.
 *
 */

#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED

#include "Vector3D.hpp"


class Ray
{
private:

    /**
    * @brief Origin of the ray.
    */
    Vector3D origin;

    /**
    * @brief Direction vector of the ray.
    */
    Vector3D direction;

public:

    /**
    * @brief Parameterized constructor
    */
    Ray(const Vector3D& origin, const Vector3D& direction);

    /**
    * @brief Returns origin of the ray.
    * @return origin attribute.
    */
    Vector3D getOrigin();

    /**
    * @brief Returns direction vector of the ray.
    * @return direction attribute.
    */
    Vector3D getDirection();
};

#endif /* RAY_HPP_INCLUDED */
