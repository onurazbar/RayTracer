/**
 *
 * @file  Object.cpp
 * @brief This file contains the implementation of Object class.
 * @note  Implemetations of pure virtual functions are in corresponding derived classes.
 *
 */

#include "Object.hpp"


Object::Object(const Vector3D& color) : color(color)
{
}

Object::~Object()
{
}

Vector3D Object::getColor()
{
	return color;
}

void Object::setColor(const Vector3D& color)
{
	this->color = color;
}