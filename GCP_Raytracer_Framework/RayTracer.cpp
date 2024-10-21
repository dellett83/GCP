#include "RayTracer.h"

glm::vec3 RayTracer::traceRay(Ray _ray)
{
	for (int i = 0; i < m_Sphere.size(); ++i)
	{
		glm::vec3 intersectionPoint = glm::vec3(0,0,0);
		if (m_Sphere.at(i)->intersect(_ray, intersectionPoint))
		{
			glm::vec3 colour = m_Sphere.at(i)->ShadeAtPos(intersectionPoint);
			return colour;
		}
	}
	return glm::vec3(0, 0, 0);
}