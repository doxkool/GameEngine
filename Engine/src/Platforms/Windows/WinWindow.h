#pragma once

//#include "Platforms/OpenGL/OpenGL_API.h"

#include "Core/Logger.h"

#include "Core/Window.h"

#include "Core/Application.h"


namespace Engine
{
	class WinWindow : public Window
	{
		public:
			WinWindow(const WindowProps& props);
			virtual ~WinWindow();

			static void Render();
			static void Update();
			static void EnableVsync(int enabled);

			static void SwapBuffer();

			virtual void* GetNativeWindow() const { return m_Window; }

			struct Window_Data
			{
				std::string Title;
				unsigned int Width, Height;
			};

		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();

		private:

			Window_Data m_Data;

			GLFWwindow* m_Window;

			// Get monitor current resolution width
			int max_width = GetSystemMetrics(SM_CXSCREEN);
			
			// Get monitor current resolution hieght
			int max_hieght = GetSystemMetrics(SM_CYSCREEN);
	};

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
}