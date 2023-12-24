#include "Core/Application.h"

//#include "EntryPoint.h"

namespace Engine
{
	Application* Application::instance = nullptr;

	Application::Application(const char *title, const int Window_Width, const int Window_Height, bool Resizable)
		:
		Window_Width(Window_Width),
		Window_Height(Window_Height)
	{
		//Init variables
		this->Window = nullptr;
		this->FrameBuffer_Width = this->Window_Width;
		this->FrameBuffer_Height = this->Window_Height;

		Log::Init();

		LOG_E_INFO("Starting new instance...");

		instance = this;

		// Initialize GLFW
		initGLFW(4, 4, Resizable);
		// Initialize the window
		initWindow(title, Window_Width, Window_Height);
	}

	Application::~Application()
	{
		glfwDestroyWindow(Window);
		glfwTerminate();
	}

	void Application::initGLFW(const int GL_VER_MAJOR, const int GL_VER_MINOR, bool Resizable)
	{
		//INIT GLFW
		if (!glfwInit())
		{
			LOG_E_CRITICAL("ERROR::GLFW_INIT_FAILED");
			glfwTerminate();
		}
		else {
			LOG_E_DEBUG("GLFW_INIT_SUCCESS");
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VER_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VER_MINOR);
		glfwWindowHint(GLFW_RESIZABLE, Resizable);
		LOG_E_DEBUG("Using OpenGL v{}.{}", GL_VER_MAJOR, GL_VER_MINOR);
	}

	void Application::initWindow(const char* title, int width, int height)
	{
		if (nullptr == Window)
		{
			Window = glfwCreateWindow(width, height, title, NULL, NULL);
			LOG_E_DEBUG("New GLFW instance : '{}' {}x{}", title, width, height);
		}

		glfwGetFramebufferSize(Window, &FrameBuffer_Width, &FrameBuffer_Height);
		glfwSetFramebufferSizeCallback(Window, framebuffer_resize_callback);

		glfwMakeContextCurrent(Window);
		LOG_E_INFO("New instance created.");

		Run();
		
	}

	int Application::Get_WindowShouldClose()
	{
		return glfwWindowShouldClose(Window);
	}

	void Application::Set_WindowShouldClose()
	{
		glfwSetWindowShouldClose(Window, GLFW_TRUE);
	}

	void Application::Run()
	{
		while (!Get_WindowShouldClose())
		{
			Update();
			Render();
		}
	}

	void Application::Update()
	{
		glfwPollEvents();
	}

	void Application::Render()
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glfwSwapBuffers(Window);

		glFlush();
	}

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height)
	{
		glViewport(0, 0, Window_Width, Window_Height);
	};
}
