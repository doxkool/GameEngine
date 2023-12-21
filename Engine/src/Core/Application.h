#pragma once

#include "Platforms/OpenGL.h"

#include "Core/Logger.h"

namespace Engine
{
	struct Game;

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);

	class Application
	{
		public:
			Application(const char *title, const int Window_Width, const int Window_Height, bool Resizable);
			~Application();

			// Functions
			void initGLFW(const int GL_VER_MAJOR, const int GL_VER_MINOR, bool Resizable);
			void initWindow(const char* title, int width, int height);
			void Update();
			void Render();

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

			GLFWwindow* Window;

		private:

		// Variables
		// Window
		const int Window_Width;
		const int Window_Height;
		int FrameBuffer_Width;
		int FrameBuffer_Height;

	};
}