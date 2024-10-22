#include "Plane.h"


Plane::Plane(glm::vec3 _position, glm::vec3 _normal, glm::vec3 _colour) 
{
	m_position = _position;
	m_normal = _normal;
	m_colour = _colour;
}


bool Plane::intersect(Ray _ray, glm::vec3& _intersectionPoint)
{
	float denominator = glm::dot(_ray.m_direction, m_normal);
	float rayPlaneInter = glm::dot((m_position - _ray.m_origin), m_normal);

	_intersectionPoint = _ray.m_origin + (rayPlaneInter * _ray.m_direction);
	return true;
}

glm::vec3 Plane::ShadeAtPos(glm::vec3 _position)
{
	return m_colour;
}

glm::vec3 Plane::NormalAtPos(glm::vec3 _intersectionPoint)
{
	return m_normal;
}


