/**
 *
 * @file  Vector.hpp
 * @brief This file defines Vector3D class.
 *
 */

#ifndef VECTOR3D_HPP_INCLUDED
#define VECTOR3D_HPP_INCLUDED

class Vector3D
{
public:

    /**
    * @brief x axis of the vector.
    */
    double x;

    /**
    * @brief y axis of the vector.
    */
    double y;

    /**
    * @brief z axis of the vector.
    */
    double z;

    /**
    * @brief Default constructor
    */
    Vector3D();

    /**
    * @brief Parameterized constructor
    */
    Vector3D(const double& x, const double& y, const double& z);

    /**
    * @brief Overloading of + operator.
    * @param v vector to use in summation operation.
    * @return Addition result.
    */
    Vector3D operator+(const Vector3D& v);

    /**
    * @brief Overloading of - operator.
    * @param v vector to use in subtraction operation.
    * @return Subtraction result.
    */
    Vector3D operator-(const Vector3D& v);

    /**
    * @brief Overloading of * operator.
    * @param v vector to product vectors.
    * @return Vector product result.
    */
    Vector3D operator*(const Vector3D& v);

    /**
    * @brief Overloading of * operator.
    * @param c to use as constant in product.
    * @return Product of vector with constant.
    */
    Vector3D operator*(const double& c);

    /**
    * @brief Cross product of two vectors.
    * @param v vector to use in cross product.
    * @return Vector that is obtained via cross product.
    */
    Vector3D crossProduct(const Vector3D& v);

    /**
    * @brief Dot product of two vectors.
    * @param v vector to use in dot product.
    * @return Dot product result.
    */
    double dotProduct(const Vector3D& v);

    /**
    * @brief Normalize the current vector.
    * @return Normalized vector.
    */
    Vector3D normalize();

    /**
    * @brief Inverse of vector according to origin.
    * @return Inversed vector.
    */
    Vector3D getInverse();
};

#endif /* VECTOR3D_HPP_INCLUDED */
