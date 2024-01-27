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

		FrameBufferWidth = OpenGL::Viewport_Width;
		FrameBufferHeight = OpenGL::Viewport_Height;
	
		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		// Adds perspective to the scene
		projection = glm::perspective(glm::radians(FOVdeg), (float)FrameBufferWidth / FrameBufferHeight, nearPlane, farPlane);
	
		// Sets new camera matrix
		cameraMatrix = projection * view;
	}

	void Camera::Matrix(const char* uniform)
	{		 
		// Exports camera matrix
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void Camera::Move(Direction direction)
	{
		switch (direction)
		{
		case Engine::FORWARD:
			cameraPos += cameraFront * MovementSpeed;
			break;
		case Engine::BACKWARD:
			cameraPos -= cameraFront * MovementSpeed;
			break;
		case Engine::LEFT:
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
			break;
		case Engine::RIGHT:
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * MovementSpeed;
			break;
		case Engine::UP:
			break;
		case Engine::DOWN:
			break;
		default:
			break;
		}
	}

	void Camera::OnUpdate(TimeStep ts)
	{
		// Check for Keyboard input
		if (Input::CheckKeyboardInput(Key::W))
		{
			Move(FORWARD);
		}
		if (Input::CheckKeyboardInput(Key::S))
		{
			Move(BACKWARD);
		}
		if (Input::CheckKeyboardInput(Key::A))
		{
			Move(LEFT);
		}
		if (Input::CheckKeyboardInput(Key::D))
		{
			Move(RIGHT);
		}

		// Check for Mouse input
		if (Input::CheckMouseButtonInput(Mouse::Button0))
		{
			LOG_E_TRACE("INPUT :: Mouse button 0 clicked.");
		}

	}
}