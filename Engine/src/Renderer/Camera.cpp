#include "Renderer/Camera.h"


// TODO :


namespace Engine
{
	Camera::Camera(CameraType type, float FOVdeg, float nearPlane, float farPlane)
		: CameraProjectionType(type), FOVdeg(FOVdeg), nearPlane(nearPlane), farPlane(farPlane)
	{
		updateMatrix();
	}

	//Camera::Camera(CameraType type, float left, float right, float bottom, float top)
	//	: CameraProjectionType(type), left(left), right(right), bottom(bottom), top(top)
	//{
	//	updateMatrix();
	//}
	
	void Camera::updateMatrix()
	{
		FrameBufferWidth = OpenGL::Viewport_Width;
		FrameBufferHeight = OpenGL::Viewport_Height;
	
		// Makes camera look in the right direction from the right position
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		//if (CameraProjectionType = Perspective)
		//{
			// Adds perspective to the scene
			projection = glm::perspective(glm::radians(FOVdeg), (float)FrameBufferWidth / FrameBufferHeight, nearPlane, farPlane);

			// Sets new camera matrix
			cameraMatrix = projection * view;

		//}
		//if (CameraProjectionType = Orthographic)
		//{
		//	projection = glm::ortho(left, right, bottom, top, 0.1f, 100.0f);
		//
		//	// Sets new camera matrix
		//	cameraMatrix = projection * view;
		//}
	}

	void Camera::PushMatrixToShader(const char* uniform)
	{		 
		// Exports camera matrix
		Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE);
	}

	void Camera::MoveCamera(Direction direction)
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
			cameraPos += cameraUp * MovementSpeed;
			break;
		case Engine::DOWN:
			cameraPos -= cameraUp * MovementSpeed;
			break;
		default:
			break;
		}
	}

	void Camera::OnUpdate(TimeStep ts)
	{

	}
}