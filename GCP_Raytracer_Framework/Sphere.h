#pragma once
#include "includes.h"
#include "RayObject.h"
#include "Ray.h"

class Sphere : RayObject
{
public:
	Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour);
	~Sphere() {}

	bool intersect(Ray _ray, glm::vec3& _intersectionPoint);
	glm::vec3 ShadeAtPos(glm::vec3 _position, glm::vec3 _lightDir);
	glm::vec3 NormalAtPos(glm::vec3 _intersectionPoint);

private:
	float m_radius;
};

