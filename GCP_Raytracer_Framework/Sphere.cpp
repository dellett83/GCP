#include "Sphere.h"

Sphere::Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour) 
{
	m_position = _position;
	m_radius = _radius;
	m_colour = glm::vec3(1, 0, 0);
}

bool Sphere::intersect(Ray _ray, glm::vec3 _intersectionPoint, glm::vec3 m_position, float m_radius)
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

glm::vec3 Sphere::ShadeAtPos(glm::vec3 _position)
{
	return m_colour;
}

glm::vec3 Sphere::NormalAtPos(glm::vec3 _intersectionPoint)
{
	glm::vec3 normal = normalize(m_position - _intersectionPoint);

	return normal;
}


