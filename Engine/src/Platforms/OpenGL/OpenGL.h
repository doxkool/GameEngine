#pragma once

#define GLEW_STATIC

#include "Core/Logger.h"

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{
	class OpenGL
	{
	public:
		OpenGL();

		void Set_ClearColor(const glm::vec4& color);

		void Clear();

	private:

	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}