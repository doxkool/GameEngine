#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Core/Logger.h"

#include "Platforms/Windows/WinWindow.h"

namespace Engine
{
	class OpenGL_API
	{
		public:
			void Init();
			void Set_Viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
			void Set_ClearColor(const glm::vec4& color);
			void Clear();

			unsigned int LoadVerticesBuffer();

			void Draw(unsigned int shaderProgram);

			void Shutdown();

		private:
			unsigned int m_shaderProgram;
			unsigned int VAO, VBO;

	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}