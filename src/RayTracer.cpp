/**
 *
 * @file  RayTracer.cpp
 * @brief This file contains the implementation of RayTracer class.
 *
 */

#include <fstream>
#include <limits>
#include "RayTracer.hpp"


RayTracer::RayTracer(const int& width, const int& height, const Vector3D& color) 
		   : canvas_width(width), canvas_height(height), background_color(color)
{
}

RayTracer::~RayTracer()
{
	for (unsigned i = 0; i < scene_objects.size(); i++)
	{
		delete scene_objects[i];
	}
	scene_objects.clear();

	for (unsigned i = 0; i < light_sources.size(); i++)
	{
		delete light_sources[i];
	}
	light_sources.clear();
}

void RayTracer::setCanvasArea(const int& width, const int& height)
{
	canvas_width = width;
	canvas_height = height;
}

void RayTracer::setCameraSettings(const Vector3D& position, const Vector3D& up_vector)
{
	// This ray tracer works with deafult camera position (0.0, 0.0, 0.0)

	// TODO: Set camera position and up vector. Define camera to world matrices
	// to be able to move the camera and change the view.
}

Vector3D RayTracer::traceRay(Ray& ray)
{
	double t_smallest = numeric_limits<double>::max();
	Object* object = nullptr;

	// Check whether the ray intersects with an scene object.
	for (unsigned i = 0; i < scene_objects.size(); i++)
	{
		double t = numeric_limits<double>::max();

		if (scene_objects[i]->checkIntersection(t, ray) && (t_smallest > t))
		{
			object = scene_objects[i];
			t_smallest = t;
		}
	}

	Vector3D color = background_color;

	if (object != nullptr)
	{
        double ambient_ratio = 0.1;
        Vector3D ambient_color;
        Vector3D diffuse_color;
		Vector3D hit_point = ray.getOrigin() + ray.getDirection()*t_smallest;
        Vector3D normal = object->getSurfaceNormal(hit_point);

        if (typeid(*object) == typeid(Plane))
        {
        	normal = (object->getSurfaceNormal(hit_point)).getInverse();
        }

        // Store objects except the current object in a vector for shadow operations
        vector<Object*> temp_objects;
        for (unsigned i = 0; i < scene_objects.size(); i++)
        {
        	if (scene_objects[i] == object)
        	{
        		continue;
        	}

        	temp_objects.push_back(scene_objects[i]);
        }

        // Calculate the color on hit point with corresponding light source.
        for (unsigned i = 0; i < light_sources.size(); i++)
        {
        	Vector3D light_vector = light_sources[i]->getCenter() - hit_point;
        	light_vector.normalize();

        	// Calculate ambient color
        	ambient_color = ambient_color + (light_sources[i]->getColor() * ambient_ratio);

        	// Calculate diffuse color
        	double diffuse_ratio = max(light_vector.dotProduct(normal), 0.0);

        	bool is_in_shadow = false;
        	Ray shadow_ray(hit_point, (light_sources[i]->getCenter() - hit_point).normalize());

        	for (unsigned i = 0; i < temp_objects.size(); i++)
			{
				double t = numeric_limits<double>::max();

				if (scene_objects[i]->checkIntersection(t, shadow_ray))
				{
					is_in_shadow = true;
					break;
				}
			}

			// If there is another object between current object and light source, do not add diffuse color.
			// object is in shadow and has only ambient color.
			if (!is_in_shadow)
			{
        		diffuse_color = diffuse_color + (light_sources[i]->getColor() * diffuse_ratio);
        	}

        	//TODO: Add specular color
        }

        // Combine all colors
        object->setColor(object->getColor().normalize());
        color = (ambient_color + diffuse_color) * object->getColor();
	}

	return color;
}

void RayTracer::render()
{
	ofstream out("image.ppm");
	out << "P3\n" << canvas_width << ' ' << canvas_height << ' ' << "255\n";

	Vector3D origin(0.0, 0.0, 0.0);
	Vector3D pixel_color(background_color);
	double aspect_ratio = canvas_width / canvas_height;

	// Go over all the pixels to assign proper color
	for (int y = 0; y < canvas_height; y++)
	{
		for (int x = 0; x < canvas_width; x++)
		{
			pixel_color = background_color;

			// Rays pass through the middle of the pixels.
            double a = (2 * (x + 0.5) / canvas_width - 1) * aspect_ratio;
            double b = (1 - 2 * (y + 0.5) / canvas_height);

            Vector3D direction(a, b, -1.0);
            direction.normalize();

			Ray ray(origin, direction);
			pixel_color = traceRay(ray);

			out << (int)pixel_color.x << ' '
          		<< (int)pixel_color.y << ' '
          		<< (int)pixel_color.z << '\n';
		}
	}
}

void RayTracer::addSphere(const Vector3D& color, const Vector3D& center, const double& radius)
{
	scene_objects.push_back(new Sphere(color, center, radius));
}

void RayTracer::addPlane(const Vector3D& color, const Vector3D& point, const Vector3D& normal)
{
	scene_objects.push_back(new Plane(color, point, normal));
}

void RayTracer::addTriangle(const Vector3D& color, const Vector3D& p1, const Vector3D& p2, const Vector3D& p3)
{
	scene_objects.push_back(new Triangle(color, p1, p2, p3));
}

void RayTracer::addLightSource(const Vector3D& color, const Vector3D& center)
{
	light_sources.push_back(new Sphere(color, center, 1.0));
}