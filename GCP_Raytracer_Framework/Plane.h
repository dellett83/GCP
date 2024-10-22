#pragma once
#include "includes.h"
#include "RayObject.h"


class Plane : RayObject
{
public:
	Plane(glm::vec3 _position, glm::vec3 _normal, glm::vec3 colour);
	~Plane() {}

	bool intersect(Ray _ray, glm::vec3& _intersectionPoint);
	glm::vec3 ShadeAtPos(glm::vec3 _position);
	glm::vec3 NormalAtPos(glm::vec3 _intersectionPoint);

private:
	glm::vec3 m_normal{ 0 };
};

