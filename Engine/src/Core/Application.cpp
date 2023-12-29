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

		Application::Run();
	}

	Application::~Application()
	{
		OpenGLAPI::Shutdown();
	}

	void Application::Run()
	{
		// TODO : Replace 'true' by glfwWindowShouldClose
		while (!Get_WindowShouldClose())
		{
			WinWindow::Update();
			WinWindow::Render();
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
