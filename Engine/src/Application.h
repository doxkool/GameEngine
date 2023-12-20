#pragma once

#include <glew.h>
#include <glfw3.h>


namespace Engine
{
	struct Game;

	bool Start_Application();

	class Application
	{
		public:
			Application(const char title, const int Window_Width, const int Window_Height, bool Resizable);
			~Application();

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

		private:

		// Variables
		// Window
		GLFWwindow* Window;
		const int Window_Width;
		const int Window_Height;
		int FrameBuffer_Width;
		int FrameBuffer_Height;

		//OpenGL Context
		const int GL_VER_MAJOR = 4;
		const int GL_VER_MINOR = 4;

	};
}