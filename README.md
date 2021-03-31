# RayTracer

This is a console based simple ray tracer application. The source code is written via C++ upon an object oriented concept.


## Project Scheme

All source(.cpp) and header(.hpp) files are placed inside the source folder **src**. I also added seven scene output images under **SampleScenes** folder as an example. Apart from that, there is also a **Makefile** that will be explained in the next section.


## Build Instructions

I added a **Makefile** to compile the source codes and create the executable application file. To build the project go to root directory **RayTracer** and simply type below command:

**make**

If you build the project for the first time all the source files will be compiled and the executable application file will be created. But in later builds only the modified and dependent source files will be compiled again.

When building the project, object folder **obj** will be created and corresponding object files will be created under this folder. Then binary folder **bin** will be created and executable application file will be created under this folder after objects are linked.

If you want to make a clean build by removing output folders and files, type below command:

**make clean**

This will remove **bin** and **obj** folders and all their contents. Then type **make** commmand again.

## Application Instructions

When you build the project, executable application file **raytracer** will be created under **bin** folder. To run the program go to **bin** folder run the executable file like below;

**./raytracer**

The program provides two main operations. You can either create the image of predefined scenes or you can create a scene and get the output image.

There are seven predefined scenes currently and you can create the image of them by selecting between 1-7. The output image file of the scene will be created under the **bin** folder as **image.ppm**.

If you want to create your own scene, you need to follow the steps on command line and provide the required information like light source number/color and object type/size/position. After you define the scene, corresponding output image is created under **bin** just like in predefined scenes.

## Notes

During setting camera positions and changing view, I faced some problems. Expecially in changing camera space to world space via matrix products. Therefore I could not add the parts about camera positions settings yet and keep camera at its original position (0.0, 0.0, 0.0). I will check this later.

Also during intersection of rays and triangles I obtained some improper outputs. Therefore I did not added triangles to sample scenes and not defined a mechanism for setting triangle settings in Main.cpp. Therefore Triangle class is currently in the project but it is not used. I will check this issue and add triangles to sample scenes after I will fix it.

## Sample Scenes


![Sample Scene 4](https://github.com/onurazbar/RayTracer/blob/main/SampleScenes/Scene_4.png)

![Sample Scene 5](https://github.com/onurazbar/RayTracer/blob/main/SampleScenes/Scene_5.png)

![Sample Scene 6](https://github.com/onurazbar/RayTracer/blob/main/SampleScenes/Scene_6.png)

![Sample Scene 7](https://github.com/onurazbar/RayTracer/blob/main/SampleScenes/Scene_7.png)
