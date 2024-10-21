#include "includes.h"
#include "Ray.h"

class Camera
{
public:
	Ray getRay(glm::ivec2 windowPos);

private:
	glm::mat4 m_projMatrix;
	glm::mat4 m_viewMatrix;

	
};

