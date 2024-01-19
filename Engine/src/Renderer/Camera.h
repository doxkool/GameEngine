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
	enum direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Camera
	{
		public:
			// Camera constructor to set up initial values
			Camera();
	
			// Updates the camera matrix to the Vertex Shader
			void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
			// Exports the camera matrix to a shader
			void Matrix(Shader* shader, const char* uniform);

			// Stores the main vectors of the camera
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

	};
}