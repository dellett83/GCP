#include "RayTracer.h"

glm::vec3 RayTracer::traceRay(Ray _ray)
{
	glm::vec3 pixelColour = glm::vec3(0.25, 0.25, 0.25);

	float closestDistance = 1000.f;

	for (int i = 0; i < m_RayObject.size(); ++i)
	{
		glm::vec3 intersectionPoint = glm::vec3(0,0,0);

		if (m_RayObject.at(i)->intersect(_ray, intersectionPoint))
		{
			glm::vec3 hitOrigin = _ray.m_origin - intersectionPoint;
			float length = glm::length(hitOrigin);
			if (length < closestDistance)
			{
				pixelColour = m_RayObject.at(i)->ShadeAtPos(intersectionPoint);
				closestDistance = length;
			}
		}
	}
	return pixelColour;
}