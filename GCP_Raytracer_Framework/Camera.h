#include "includes.h"

class Camera
{
	Camera(glm::mat4 _projMatrix, glm::mat4 _viewMatrix);
	~Camera();
private:
	glm::mat4 m_projMatrix;
	glm::mat4 m_viewMatrix;
};

