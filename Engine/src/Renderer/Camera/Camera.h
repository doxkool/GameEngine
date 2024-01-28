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

	class Camera
	{
		public:
			// For creating a perspective camera
			Camera() {}

			// Exports the camera matrix to a shader
			virtual void PushMatrixToShader(const char* uniform) { Shader::setMat4fv(cameraMatrix, uniform, GL_FALSE); }

		public:

			// Stores the camera matrix
			glm::mat4 cameraMatrix = glm::mat4(1.0f);

	};
}