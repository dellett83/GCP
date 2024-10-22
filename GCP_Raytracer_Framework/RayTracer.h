#pragma once
#include "includes.h"
#include "RayObject.h"
#include "Ray.h"
#include <vector>

class RayTracer
{
public:

	glm::vec3 traceRay(Ray _ray);
	std::vector<RayObject*> m_RayObject;
	
};

