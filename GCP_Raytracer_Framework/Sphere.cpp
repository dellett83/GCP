#include "Sphere.h"

Sphere::Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour) 
{
	m_position = _position;
	m_radius = _radius;
	m_colour = _colour;
}

bool Sphere::intersect(Ray _ray, glm::vec3& _intersectionPoint)
{
	glm::vec3 distPosOrigin = m_position - _ray.m_origin;
	float tc = glm::dot(distPosOrigin, _ray.m_direction);

	if (tc < 0.0) return false;
	float d2 = glm::dot(distPosOrigin, distPosOrigin) - (tc * tc);

	float radius2 = m_radius * m_radius;
	if (d2 > radius2) return false;

	float t1c = glm::sqrt(radius2 - d2);

	float t1 = tc - t1c;

	_intersectionPoint = _ray.m_origin + (_ray.m_direction * t1);

	return true;
}

glm::vec3 Sphere::ShadeAtPos(glm::vec3 _position, glm::vec3 _lightDir)
{
	glm::vec3 lightColour = glm::vec3(1,1,1);
	glm::vec3 lightDir = glm::normalize(_lightDir);
	glm::vec3 matColour = m_colour;
	glm::vec3 normal = NormalAtPos(_position);
	glm::vec3 L = glm::dot(lightDir, normal) * lightColour * matColour;

	return L;
}

glm::vec3 Sphere::NormalAtPos(glm::vec3 _intersectionPoint)
{
	glm::vec3 normal = normalize(_intersectionPoint - m_position);

	return normal;
}


