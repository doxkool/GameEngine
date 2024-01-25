#include "Renderer/Camera.h"


// TODO :
// - Be able the get the correct window dimmention from OpenGL.cpp

namespace Engine
{
	Camera::Camera(CameraType type)
	{
		this->EntityID;
	}
	
	void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
	{
		// Initializes matrices since otherwise they will be the null matrix
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
	
		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		// Adds perspective to the scene
		projection = glm::perspective(glm::radians(FOVdeg), (float)1000 / 1000, nearPlane, farPlane);
	
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void Camera::Matrix(const char* uniform)
	{		 
		// Exports camera matrix
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void Camera::Move(Direction direction, float speed)
	{
		switch (direction)
		{
		case Engine::FORWARD:
			cameraPos += speed * cameraFront;
			break;
		case Engine::BACKWARD:
			cameraPos -= speed * cameraFront;
			break;
		case Engine::LEFT:
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
			break;
		case Engine::RIGHT:
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
			break;
		case Engine::UP:
			break;
		case Engine::DOWN:
			break;
		default:
			break;
		}
	}
}