#include "Application.h"

namespace Engine
{
	bool Start_Application()
	{
		Application instance('test',1280,720,false);

		while (!instance.Get_WindowShouldClose())
		{
			
		}

		return true;
	}

	Application::Application(const char title, const int Window_Width, const int Window_Height, bool Resizable)
	:
	Window_Width(Window_Width),
	Window_Height(Window_Height)
	{
		//Init variables
		this->Window = nullptr;
		this->FrameBuffer_Width = this->Window_Width;
		this->FrameBuffer_Height = this->Window_Height;

		

	}

	Application::~Application()
	{
		
	}

	int Application::Get_WindowShouldClose()
	{
		return 0;
	}

	void Application::Set_WindowShouldClose()
	{
		
	}
}
