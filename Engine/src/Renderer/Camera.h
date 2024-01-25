#pragma once

#include "Core/Logger.h"

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
			// Camera constructor to set up initial values
			Camera(CameraType type);
	
			// Updates the camera matrix to the Vertex Shader
			void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
			// Exports the camera matrix to a shader
			void Matrix(const char* uniform);

			void Move(Direction direction, float speed);

		public:
			
			int EntityID;

			// Stores the main vectors of the camera
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
			glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
			glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

			float cameraSpeed = 0.05f;

	};
}