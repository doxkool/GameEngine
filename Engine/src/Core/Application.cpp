#include "Core/Application.h"

namespace Engine
{
	Application* Application::s_instance = nullptr;

	Application::Application(const AppSpec& specification)
		: m_spec(specification)
	{
		Log::Init();

		// Set working directory here
		if (m_spec.WorkingDirectory.empty())
		{
			LOG_E_ERROR ("No working directory defined!");
		}

		LOG_E_INFO("Setting working directory to : '{}'", m_spec.WorkingDirectory);

		s_instance = this;

		m_Window = Window::Create(WindowProps(m_spec.title));

		WinWindow::EnableVsync(1);

		Application::Run();
	}

	Application::~Application()
	{
		OpenGLAPI::Shutdown();
	}

	void Application::ShowEngineStats(EngineStats options)
	{
		std::string FPS;
		std::string ms;

		if (options.Show_FPS)
		{
			FPS = std::to_string(perf.Get_FPS());
		}
		if (options.Show_Frame_Time)
		{
			ms = std::to_string(perf.Get_FrameTime());
		}

		std::string newTitle = m_spec.title + " " + FPS + "FPS / " + ms + "ms";

		// TODO : Remove as soon glfwSetWindowTitle has been moved to WinWindow
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		// TODO : Add a function to update the window title in WinWindow
		glfwSetWindowTitle(window, newTitle.c_str());
	}

	void Application::Run()
	{
		m_EngineStats.Show_FPS = true;
		m_EngineStats.Show_Frame_Time = true;

		while (!Get_WindowShouldClose())
		{

			perf.StartTime(Time::GetTime());

			ShowEngineStats(m_EngineStats);

			WinWindow::Update();
			WinWindow::Render();

			perf.EndTime();
		}

		LOG_E_TRACE("Total session runtime : {}", m_TimeStep.Get_Seconds());
	}

	int Application::Get_WindowShouldClose()
	{
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		return glfwWindowShouldClose(window);
	}

	void Application::Set_WindowShouldClose()
	{	
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		glfwSetWindowShouldClose(window, GLFW_TRUE);

	}
}
