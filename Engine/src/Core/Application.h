#pragma once

#include "Core/Base.h"

#include "Platforms/OpenGL/OpenGL.h"

#include "Platforms/Windows/WinWindow.h"

#include "Core/LayerStack.h"
#include "Core/Logger.h"
#include "Core/Time.h"
#include "Core/Utilities/Utilities.h"
#include "Core/Input/Input.h"

int main();

namespace Engine
{

	struct AppSpec
	{
		std::string title = "Game";
		std::string WorkingDirectory;
		bool Windowed = true;
		int Window_Width = 1920;
		int Window_Height = 1080;
	};

	struct EngineStats
	{
		bool Show_FPS = false;
		bool Show_Frame_Time = false;
	};

	class Application
	{
		public:
			Application(const AppSpec& specification);
			~Application();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			void Run();

			void ShowEngineStats(EngineStats options);

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
			LayerStack m_LayerStack;

			float AppRunTime = 0.0f;
	};

	// To be defined in CLIENT
	Application* CreateApplication(AppSpec);
}