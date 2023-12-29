#pragma once

#include "Core/Base.h"

#include "Core/Window.h"
#include "Platforms/OpenGL/OpenGL_API.h"
#include "Platforms/Windows/WinWindow.h"
#include "Core/Logger.h"

int main();

namespace Engine
{

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

			void Run();

			int Get_WindowShouldClose();
			void Set_WindowShouldClose();

			Window& GetWindow() { return *m_Window; }

			static Application& Get() { return *s_instance; }

		private:
			bool Running = true;

			static Application* s_instance;

			AppSpec m_spec;

			Pointer<Window> m_Window;

	};

	// To be defined in CLIENT
	Application* CreateApplication(AppSpec);
}