#pragma once

#include "Core/Logger.h"
#include "Core/Time.h"
#include "Core/Input/Input.h"

#include "Platforms/OpenGL/OpenGL.h"

#include "Renderer/shader.h"

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace Engine
{	
	enum Direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };
	enum CameraType { Perspective, Orthographic	};

	class Camera
	{
		public:
			// For creating a perspective camera
			Camera(CameraType type, float FOVdeg, float nearPlane, float farPlane);
			// For creating a orthographic camera
			//Camera(CameraType type, float left, float right, float bottom, float top);

			// Updates the camera matrix to the Vertex Shader
			void updateMatrix();
			// Exports the camera matrix to a shader
			void PushMatrixToShader(const char* uniform);

			void SetMovementSpeed(float Speed) { MovementSpeed = Speed; }
			void SetMouseRotationSpeed(float Speed) { MouseRotationSpeed = Speed; }
			void SetMousePanningSpeed(float Speed) { MousePanningSpeed = Speed; }
			void SetMouseScrollSpeed(float Speed) { MouseScrollSpeed = Speed; }

			float GetMovementSpeed() { return MovementSpeed; }
			float GetMouseRotationSpeed() { return MouseRotationSpeed; }
			float GetMousePanningSpeed() { return MousePanningSpeed; }
			float GetMouseScrollSpeed() { return MouseScrollSpeed; }

			void MoveCamera(Direction direction);

			void OnUpdate(TimeStep ts);

		public:
			
			CameraType CameraProjectionType;

			// Variables for perspective camera
			float FOVdeg;
			float nearPlane;
			float farPlane;

			// Variables for orthographic camera
			float left;
			float right;
			float bottom;
			float top;

			// Stores the main vectors of the camera
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

			glm::mat4 view = glm::mat4(1.0f);
			glm::mat4 projection = glm::mat4(1.0f);

			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
			glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
			glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

			float MovementSpeed = 0.1f;
			float MouseRotationSpeed = 0.1f;
			float MousePanningSpeed = 0.1f;
			float MouseScrollSpeed = 0.1f;

			int FrameBufferWidth = 0;
			int FrameBufferHeight = 0;

	};
}