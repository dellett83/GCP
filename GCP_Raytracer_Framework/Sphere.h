#include "includes.h"
#include "Ray.h"

struct Sphere
{
	Sphere(glm::vec3 _position, float _radius, glm::vec3 _colour);
	~Sphere() {}

	bool intersect(Ray _ray, glm::vec3 _intersectionPoint, glm::vec3 m_position, float m_radius);

	glm::vec3 ShadeAtPos(glm::vec3 _position);
	glm::vec3 NormalAtPos(glm::vec3 _intersectionPoint);

private:
	glm::vec3 m_position;
	float m_radius;
	glm::vec3 m_colour;
};

