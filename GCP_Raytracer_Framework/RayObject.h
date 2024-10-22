#pragma once
#include "includes.h"
#include "Ray.h"

class RayObject
{
public:
	RayObject() {}
	~RayObject() {}
	
	virtual bool intersect(Ray _ray, glm::vec3& _intersectionPoint) = 0;
	virtual glm::vec3 ShadeAtPos(glm::vec3 _position) = 0;
	virtual glm::vec3 NormalAtPos(glm::vec3 _intersectionPoint) = 0;

protected:
	glm::vec3 m_position;
	glm::vec3 m_colour;
};

