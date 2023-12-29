#pragma once

#include "Core/Base.h"

#include "Core/Window.h"
#include "Platforms/OpenGL/OpenGL_API.h"
#include "Platforms/Windows/WinWindow.h"
#include "Core/Logger.h"
#include "Core/Time.h"

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

	struct EngineStats
	{
		double FPS = 0.0;
		double Frame_Time = 0.0;
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

			TimeStep m_TimeStep;

			EngineStats m_EngineStats;
			static Application* s_instance;
			AppSpec m_spec;
			Pointer<Window> m_Window;

			Perf perf;

			float AppRunTime = 0.0f;
	};

	// To be defined in CLIENT
	Application* CreateApplication(AppSpec);
}