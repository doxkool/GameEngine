#pragma once

#include "OpenGL/OpenGL.h"

#include "OpenGL/OpenGLInput.h"

namespace Engine
{
	struct Window_Params
	{
		std::string Window_Title = "";
		int Window_Width = 0;
		int Window_Height = 0;
		bool Window_Resizeable = true;
		bool FullScreen_mode = false;
	};

	struct Monitor_Spec
	{
		int MonitorID = 0;
		const char* MonitorName = "";
		bool PrimaryMonitor = true;
	};

	class OpenGLWindow
	{
	public:
		void SetWindow(const std::string Window_Title = "Game", const int Window_Width = 0, const int Window_Height = 0, const bool Window_Resizeable = true);

		void DetectMonitors();

		void SetWindowUserPointer(OpenGLWindow window);

		void UpdateWindowTitle(const std::string Window_Title = "Game");

		int Get_WindowShouldClose();
		void Set_WindowShouldClose();

		GLFWwindow* GetNativeWindow() { return m_Window; }

		static void Update();
		void SwapBuffer();

		static void EnableVsync(int enabled);

		bool CheckKeyboardInput(uint16_t key);
		bool CheckMouseButtonInput(uint16_t button);

		glm::vec2 GetMousePosition();
		float GetMouseX();
		float GetMouseY();

	public:
		Window_Params WinParams;
		std::vector<Monitor_Spec> MonitorsSpec;

	private:
		GLFWwindow* m_Window;
	};

	class WindowCallback
	{
	public:
		WindowCallback(OpenGLWindow& window);

		static void GLFWErrorCallback(int error, const char* message);

		static void MonitorCallback(GLFWmonitor* monitor, int event);
		static void WindowResizeCallback(GLFWwindow* Window, int Window_Width, int Window_Height);
		static void FramebufferResizeCallback(GLFWwindow* Window, int Window_Width, int Window_Height);
		static void WindowPositionCallback(GLFWwindow* Window, int xPos, int yPos);
		static void WindowMaximizeCallback(GLFWwindow* Window, int maximized);

	};
}