#include "Core/Application.h"

namespace Engine
{
	Application* Application::s_instance = nullptr;

	Application::Application(const AppSpec& specification)
		: m_spec(specification)
	{
		Logger::Init();
		
		// Check if the working directory is empty
		if (m_spec.WorkingDirectory.empty())
		{
			LOG_E_WARN ("No custom working directory defined.");

			m_spec.WorkingDirectory = "/";
		}

		LOG_E_INFO("Setting working directory to : '{}'", m_spec.WorkingDirectory);

		s_instance = this;

		m_Window = Window::Create(WindowProps(m_spec.title));

		OpenGL_API::Set_Viewport(m_spec.Window_Width, m_spec.Window_Height, m_spec.Window_Width, m_spec.Window_Height);

	}

	Application::~Application()
	{
		LOG_E_DEBUG("Clossing Application...");
	}

	void Application::ShowEngineStats(EngineStats options)
	{
		std::string str_FPS;
		std::string str_FrameTime;

		if (options.Show_FPS)
		{
			str_FPS = std::to_string(perf.Get_FPS());
		}
		if (options.Show_Frame_Time)
		{
			str_FrameTime = std::to_string(perf.Get_FrameTime());
		}

		std::string newTitle = m_spec.title + " " + str_FPS + "fps / " + str_FrameTime + "ms";

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

			perf.StartPerfCounter();

			ShowEngineStats(m_EngineStats);

			WinWindow::Update();
			WinWindow::Render();

			perf.EndPerfCounter();
		}
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