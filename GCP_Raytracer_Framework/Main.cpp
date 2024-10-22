
#include "GCP_GFX_Framework.h"

#include "RayTracer.h"
#include "Ray.h"
#include "RayObject.h"
#include "Sphere.h"
#include "Camera.h"
#include "Plane.h"



int main(int argc, char* argv[])
{
	// Set window size
	glm::ivec2 winSize(1280, 720);

	// This will handle rendering to screen
	GCP_Framework _myFramework;

	// Initialises SDL and OpenGL and sets up a framebuffer
	if (!_myFramework.Init(winSize))
	{
		return -1;
	}

	RayTracer Raytracer;
	Camera mainCam(winSize, glm::vec3(0,0,0));

	Sphere Red = Sphere(glm::vec3(5,0, -75), 10, glm::vec3(1, 0, 0));
	Sphere Blue = Sphere(glm::vec3(-5,0, -50), 10, glm::vec3(1, 0, 0));

	Raytracer.m_RayObject.push_back((RayObject*)&Red);
	Raytracer.m_RayObject.push_back((RayObject*)&Blue);

	Plane plane(glm::vec3(0, -5, -50), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0));
	Raytracer.m_RayObject.push_back((RayObject*)&plane);

	for (int y = 0; y < winSize.y; ++y)
	{
		for (int x = 0; x < winSize.x; ++x)
		{
			Ray newRay = mainCam.getRay(glm::ivec2(x, y), winSize);
			glm::vec3 colour = Raytracer.traceRay(newRay);

			_myFramework.DrawPixel(glm::ivec2(x,y), colour);
		}
	}

	// Pushes the framebuffer to OpenGL and renders to screen
	// Also contains an event loop that keeps the window going until it's closed
	_myFramework.ShowAndHold();
	return 0;


}
