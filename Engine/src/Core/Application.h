#pragma once

#include "Core/Base.h"

#include "Platforms/OpenGL.h"
#include "Core/Logger.h"

int main();

namespace Engine
{

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);

	struct AppSpec
	{
		std::string title = "Game";
		std::string WorkingDirectory;
		int Window_Width = 1920;
		int Window_Height = 1080;
		bool Resizable = false;
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

		private:

		// Variables
		AppSpec m_spec;
		
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