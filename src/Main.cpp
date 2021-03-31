/**
 *
 * @file  Main.cpp
 * @brief This file contains main function of the ray tracer application.
 *
 */

#include <iostream>
#include "RayTracer.hpp"


void renderSampleScene1()
{
    cout << "A blue ball and a white light source" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(0.0, 0.0, -25.0), 5.0);
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 10.0, -25.0));
    raytracer.render();
}

void renderSampleScene2()
{
    cout << "A blue ball and two white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(0.0, 0.0, -25.0), 5.0);
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 10.0, -25.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(10.0, 10.0, -25.0));
    raytracer.render();
}

void renderSampleScene3()
{
    cout << "A blue ball, a red ball and two white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(-3.0, 0.0, -25.0), 5.0);
    raytracer.addSphere(Vector3D(251.0, 10.0, 10.0), Vector3D(1.0, 0.0, -50.0), 15.0);
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 20.0, -25.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(10.0, 20.0, -25.0));
    raytracer.render();
}

void renderSampleScene4()
{
    cout << "A blue ball, a plane and a white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(0.0, 0.0, -35.0), 5.0);
    raytracer.addPlane(Vector3D(240.0, 240.0, 240.0), Vector3D(0.0, -5.0, -50.0), Vector3D(0.0, -1.0, 0.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 10.0, -35.0));
    raytracer.render();
}

void renderSampleScene5()
{
    cout << "A blue ball, a plane and two white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(0.0, 0.0, -35.0), 5.0);
    raytracer.addPlane(Vector3D(240.0, 240.0, 240.0), Vector3D(0.0, -5.0, -50.0), Vector3D(0.0, -1.0, 0.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 10.0, -35.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(10.0, 10.0, -35.0));
    raytracer.render();
}

void renderSampleScene6()
{
    cout << "A blue ball, a red ball, a green ball, a plane and two white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(21.0, 98.0, 254.0), Vector3D(0.0, 0.0, -35.0), 5.0);
    raytracer.addSphere(Vector3D(251.0, 10.0, 10.0), Vector3D(-10.0, -2.0, -15.0), 3.0);
    raytracer.addSphere(Vector3D(10.0, 240.0, 10.0), Vector3D(10.0, -2.0, -15.0), 3.0);
    raytracer.addPlane(Vector3D(240.0, 240.0, 240.0), Vector3D(0.0, -5.0, -50.0), Vector3D(0.0, -1.0, 0.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(-10.0, 10.0, -35.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(10.0, 10.0, -35.0));
    raytracer.render();
}

void renderSampleScene7()
{
    cout << "Two balls, a tilted plane and two white light sources" << endl;

    RayTracer raytracer(1024, 768, Vector3D());
    raytracer.addSphere(Vector3D(65.0, 98.0, 97.0), Vector3D(0.0, 0.0, -35.0), 5.0);
    raytracer.addSphere(Vector3D(35.0, 125.0, 10.0), Vector3D(10.0, -2.0, -15.0), 3.0);
    raytracer.addPlane(Vector3D(240.0, 240.0, 240.0), Vector3D(-10.0, -10.0, 0.0), Vector3D(-1.0, -2.0, 0.0));
    raytracer.addLightSource(Vector3D(200.0, 220.0, 180.0), Vector3D(10.0, 20.0, -35.0));
    raytracer.addLightSource(Vector3D(255.0, 255.0, 255.0), Vector3D(20.0, 10.0, -20.0));
    raytracer.render();
}

int main()
{
    cout << "--- Ray Tracer Application ---" << endl;

    while (true)
    {
        cout << "Enter 1 to render one of the sample scenes" << endl;
        cout << "Enter 2 to render an image by adding objects and lights sources" << endl;

        int selection = 0;

        cin >> selection;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << std::endl << "Invalid selection!" << endl << endl;
            continue;
        }
        else if (selection == 1)
        {
            cout << "There are seven sample scenes enter a number from 1 to 7 to render corresponding scene" << endl;
            cin >> selection;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << endl << "Invalid selection!" << endl << endl;
                continue;
            }
            else if (selection == 1)
            {
                renderSampleScene1();
            }
            else if (selection == 2)
            {
                renderSampleScene2();
            }
            else if (selection == 3)
            {
                renderSampleScene3();
            }
            else if (selection == 4)
            {
                renderSampleScene4();
            }
            else if (selection == 5)
            {
                renderSampleScene5();
            }
            else if (selection == 6)
            {
                renderSampleScene6();
            }
            else if (selection == 7)
            {
                renderSampleScene7();
            }
            else
            {
                cout << endl << "Invalid selection!" << endl << endl;
            }
        }
        else if (selection == 2)
        {
            int canvas_width = 0;
            int canvas_height = 0;
            RayTracer raytracer(1024, 768, Vector3D());

            cout << "Make selections for below cases to create your own scene" << endl;
            cout << "Enter canvas width as integer" << endl;
            cin >> canvas_width;

            cout << "Enter canvas height as integer" << endl;
            cin >> canvas_height;

            cout << "Do you want to add spheres? Enter 1 for YES / Enter 2 for NO" << endl;
            cin >> selection;

            if (selection == 1)
            {
                double red = 0.0;
                double green = 0.0;
                double blue = 0.0;
                double x = 0.0;
                double y = 0.0;
                double z = 0.0;
                double radius = 0.0;

                cout << "How many spheres do you want to add? Enter sphere count" << endl;
                cin >> selection;

                for (int i = 0; i < selection; i++)
                {
                    cout << "Set parameters of sphere " << (i + 1) << endl;
                    cout << "Enter RGB values one by one as doubles" << endl;
                    cin >> red;
                    cin >> green;
                    cin >> blue;

                    cout << "Enter x,y,z coordinate values one by one as doubles" << endl;
                    cin >> x;
                    cin >> y;
                    cin >> z;

                    cout << "Enter radius as double" << endl;
                    cin >> radius;

                    raytracer.addSphere(Vector3D(red, green, blue), Vector3D(x, y, z), radius);
                }
            }

            cout << "Do you want to add light sources? Enter 1 for YES / Enter 2 for NO" << endl;
            cin >> selection;

            if (selection == 1)
            {
                double red = 0.0;
                double green = 0.0;
                double blue = 0.0;
                double x = 0.0;
                double y = 0.0;
                double z = 0.0;

                cout << "How many light sources do you want to add? Enter light source count" << endl;
                cin >> selection;

                for (int i = 0; i < selection; i++)
                {
                    cout << "Set parameters of light source " << (i + 1) << endl;
                    cout << "Enter RGB values one by one as doubles" << endl;
                    cin >> red;
                    cin >> green;
                    cin >> blue;

                    cout << "Enter x,y,z coordinate values one by one as doubles" << endl;
                    cin >> x;
                    cin >> y;
                    cin >> z;

                    raytracer.addLightSource(Vector3D(red, green, blue), Vector3D(x, y, z));
                }
            }

            cout << "Do you want to add planes? Enter 1 for YES / Enter 2 for NO" << endl;
            cin >> selection;

            if (selection == 1)
            {
                double red = 0.0;
                double green = 0.0;
                double blue = 0.0;
                double x = 0.0;
                double y = 0.0;
                double z = 0.0;
                double vx = 0.0;
                double vy = 0.0;
                double vz = 0.0;

                cout << "How many planes do you want to add? Enter plane count" << endl;
                cin >> selection;

                for (int i = 0; i < selection; i++)
                {
                    cout << "Set parameters of plane " << (i + 1) << endl;
                    cout << "Enter RGB values one by one as doubles" << endl;
                    cin >> red;
                    cin >> green;
                    cin >> blue;

                    cout << "Enter x,y,z coordinate values of plane point one by one as doubles" << endl;
                    cin >> x;
                    cin >> y;
                    cin >> z;

                    cout << "Enter x,y,z coordinate values of plane normal one by one as doubles" << endl;
                    cin >> vx;
                    cin >> vy;
                    cin >> vz;

                    raytracer.addPlane(Vector3D(red, green, blue), Vector3D(x, y, z), Vector3D(vx, vy, vz));
                }
            }

            cout << "Scene is rendering according to your selections. Check image.ppm file to see image" << endl;
            raytracer.render();
        }
    }

    return 0;
}
