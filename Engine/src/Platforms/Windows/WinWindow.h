#pragma once

#include "Core/Logger.h"

#include "Core/Window.h"

#include "Core/Application.h"


namespace Engine
{
	struct Window_Data
	{
		std::string Title;
		unsigned int Width, Height;
	};

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

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);

	static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
	static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);
}