#pragma once
#include "includes.h"
#include "Sphere.h"
#include "Ray.h"
#include <vector>

class RayTracer
{
public:

	glm::vec3 traceRay(Ray _ray);
	std::vector<Sphere*> m_Sphere;
	
};

