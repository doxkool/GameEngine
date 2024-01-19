#include "Renderer/Camera.h"

namespace Engine
{
	Camera::Camera()
	{
	}
	
	void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
	{
		// Initializes matrices since otherwise they will be the null matrix
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
	
		// Makes camera look in the right direction from the right position
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		// Adds perspective to the scene
		projection = glm::perspective(glm::radians(FOVdeg), (float)1000 / 1000, nearPlane, farPlane);
	
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void Camera::Matrix(Shader* shader, const char* uniform)
	{		 
		// Exports camera matrix
		glUniformMatrix4fv(glGetUniformLocation(shader->ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
	}
}