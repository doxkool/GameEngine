#pragma once

#include "Platforms/OpenGL.h"
#include "Core/Logger.h"

int main();

namespace Engine
{

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);

	struct AppSpec
	{
		std::string title = "My App";
		int Window_Width = 1280;
		int Window_Height = 720;
		bool Resizable = true;
	};

	class Application
	{
		public:
			Application(const AppSpec& specification);
			~Application();

			// Functions
			void initGLFW(const int GL_VER_MAJOR, const int GL_VER_MINOR, bool Resizable);
			void initWindow(std::string title, int width, int height);
			void Run();
			void Update();
			void Render();

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

			GLFWwindow* Window;
			static Application* instance;

			AppSpec m_spec;

		private:

		// Variables
		
		// Window
		//const char c_title;
		int c_Window_Width;
		int c_Window_Height;
		int FrameBuffer_Width;
		int FrameBuffer_Height;

	};

	// To be defined in CLIENT
	Application* CreateApplication(AppSpec);
}