#include "Camera.h"

Ray Camera::getRay(glm::ivec2 windowPos)
{
	Ray newRay;
	newRay.m_origin = glm::vec3(windowPos, 0);
	newRay.m_direction = glm::vec3(0, 0, -1);
	return newRay;
}