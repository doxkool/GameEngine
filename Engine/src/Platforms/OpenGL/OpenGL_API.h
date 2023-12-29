#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Core/Logger.h"

#include "Platforms/Windows/WinWindow.h"

namespace Engine
{
	class OpenGLAPI
	{
		public:
			static void Init();
			static void Set_Viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
			static void Set_ClearColor(const glm::vec4& color);
			static void Clear();
			static void SwapBuffer();

			static void Shutdown();

		private:
		
		

	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}