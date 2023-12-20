#include "Core/Application.h"

namespace Engine
{
	bool Start_Application(const char* title, const int Window_Width, const int Window_Height, bool Resizable)
	{
		const char *AppName = title;
		Application instance(AppName, Window_Width, Window_Height, Resizable);

		while (!instance.Get_WindowShouldClose())
		{
		
		}

		return true;
	}

	Application::Application(const char *title, const int Window_Width, const int Window_Height, bool Resizable)
	:
	Window_Width(Window_Width),
	Window_Height(Window_Height)
	{
		//Init variables
		//this->Window = nullptr;
		//this->FrameBuffer_Width = this->Window_Width;
		//this->FrameBuffer_Height = this->Window_Height;

		// Initialize GLFW
		initGLFW(4,4);
		initWindow(title, Window_Width, Window_Height);

	}

	Application::~Application()
	{
		//glfwDestroyWindow(this->Window);
		glfwTerminate();
	}

	int Application::Get_WindowShouldClose()
	{
		//return glfwWindowShouldClose(this->Window);
		return 0;
	}

	void Application::Set_WindowShouldClose()
	{
		//glfwSetWindowShouldClose(this->Window, GLFW_TRUE);
	}
}
