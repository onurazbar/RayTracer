/**
 *
 * @file  RayTracer.hpp
 * @brief This file defines RayTracer class.
 *
 */

#ifndef RAYTRACER_HPP_INCLUDED
#define RAYTRACER_HPP_INCLUDED

#include <vector>
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"

using namespace std;


class RayTracer
{
private:

    /**
    * @brief Width of the canvas in pixels.
    */
    int canvas_width;

    /**
    * @brief Height of the canvas in pixels.
    */
    int canvas_height;

    /**
    * @brief Position of the camera.
    */
    Vector3D camera_position;

    /**
    * @brief Up vector.
    */
    Vector3D up_vector;

    /**
    * @brief background color in RGB.
    */
    Vector3D background_color;

    /**
    * @brief Vector that stores objects of the scene with Object* pointers.
    */
    vector<Object*> scene_objects;

    /**
    * @brief Vector that stores light sources of the scene with Sphere* pointers.
    */
    vector<Sphere*> light_sources;

    /**
    * @brief Detects whether ray is intersect any of the scene object and assigns a proper
    *        color for the corrsponding pixel.
    * @param ray the ray that comes from camera through the corresponding pixel.
    * @return color of the pixel in RGB.
    */
    Vector3D traceRay(Ray& ray);

public:

    /**
    * @brief Parameterized constructor.
    */
    RayTracer(const int& width, const int& height, const Vector3D& color);

    /**
    * @brief Destructor.
    */
    ~RayTracer();

    /**
    * @brief Sets canvas size parameters.
    * @param width to be set.
    * @param height to be set.
    */
    void setCanvasArea(const int& width, const int& height);

    /**
    * @brief Sets camera position and up vector.
    * @param position to be set.
    * @param up_vector to be set.
    */
    void setCameraSettings(const Vector3D& position, const Vector3D& up_vector);

    /**
    * @brief Renders the image with pixel colors and fills output file.
    */
    void render();

    /**
    * @brief Adds sphere objects to the scene.
    * @param color to be set.
    * @param center to be set.
    * @param radius to be set.
    */
    void addSphere(const Vector3D& color, const Vector3D& center, const double& radius);

    /**
    * @brief Adds plane objects to the scene.
    * @param color to be set.
    * @param point to be set.
    * @param normal to be set.
    */
    void addPlane(const Vector3D& color, const Vector3D& point, const Vector3D& normal);

    /**
    * @brief Adds triangle objects to the scene.
    * @param color to be set.
    * @param p1 first point to be set.
    * @param p2 second point to be set.
    * @param p3 third point to be set.
    */
    void addTriangle(const Vector3D& color, const Vector3D& p1, const Vector3D& p2, const Vector3D& p3);

    /**
    * @brief Adds light sources to the scene. Light sources are considered as spheres with the radius 1.0.
    * @param color to be set.
    * @param center to be set.
    */
    void addLightSource(const Vector3D& color, const Vector3D& center);
};

#endif /* RAYTRACER_HPP_INCLUDED */
