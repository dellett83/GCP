
#include "GCP_GFX_Framework.h"

#include "RayTracer.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"



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
	Camera mainCam;

	Sphere* Red = new Sphere(glm::vec3((winSize.x/2),(winSize.y/2), -100), 100, glm::vec3(1, 0, 0));
	Sphere* Blue = new Sphere(glm::vec3((winSize.x/3), (winSize.y / 2), -100), 100, glm::vec3(1, 0, 0));

	Raytracer.m_Sphere.push_back(Red);
	Raytracer.m_Sphere.push_back(Blue);

	for (int y = 0; y < winSize.y; ++y)
	{
		for (int x = 0; x < winSize.x; ++x)
		{
			Ray newRay = mainCam.getRay(glm::ivec2(x, y));
			glm::vec3 colour = Raytracer.traceRay(newRay);

			_myFramework.DrawPixel(glm::ivec2(x,y), colour);
		}
	}

	// Pushes the framebuffer to OpenGL and renders to screen
	// Also contains an event loop that keeps the window going until it's closed
	_myFramework.ShowAndHold();
	return 0;


}
