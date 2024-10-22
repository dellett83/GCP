#include "Camera.h"
#include <iostream>

#include <GLM/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::ivec2 _winSize, glm::vec3 _position)
{
	m_viewMatrix = glm::translate(m_viewMatrix, _position);
	m_viewMatrix = glm::inverse(m_viewMatrix);

	m_projMatrix = glm::perspective(glm::radians(60.0f), (float)_winSize.x / (float)_winSize.y, 0.1f, 100.0f);
}

Ray Camera::getRay(glm::ivec2 windowPos, glm::ivec2 winSize)
{
	glm::vec2 fWinPos((float)windowPos.x, (float)windowPos.y);
	glm::vec2 fWinSize((float)winSize.x, (float)winSize.y);

	glm::vec4 nearPoint;
	nearPoint.x = ((fWinPos.x / fWinSize.x) - 0.5f) * 2;
	nearPoint.y = ((fWinPos.y / fWinSize.y) - 0.5f) * 2;
	nearPoint.z = -1;
	nearPoint.w = 1;

	glm::vec4 farPoint = nearPoint;
	farPoint.z = 1;

	nearPoint = inverse(m_projMatrix) * nearPoint;
	farPoint = inverse(m_projMatrix) * farPoint;

	nearPoint = nearPoint / nearPoint.w;
	farPoint = farPoint / farPoint.w;

	nearPoint = nearPoint * m_viewMatrix;
	farPoint = farPoint * m_viewMatrix;

	Ray newRay;
	newRay.m_origin = nearPoint;
	glm::vec3 dir = glm::normalize(farPoint - nearPoint);
	newRay.m_direction = dir;
	return newRay;
}