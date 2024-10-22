#include "includes.h"
#include "Ray.h"

class Camera
{
public:
	Camera(glm::ivec2 _winSize, glm::vec3 _position);
	~Camera() {}
	
	Ray getRay(glm::ivec2 windowPos, glm::ivec2 winSize);

private:
	glm::mat4 m_projMatrix{ 1.0f };
	glm::mat4 m_viewMatrix{ 1.0f };

	
};

