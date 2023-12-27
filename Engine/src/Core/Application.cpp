#include "Core/Application.h"

//#include "EntryPoint.h"



namespace Engine
{
	Application* Application::instance = nullptr;

	Application::Application(const AppSpec& specification)
		: m_spec(specification)
	{
		//Init variables
		this->Window = nullptr;
		this->FrameBuffer_Width = this->c_Window_Width;
		this->FrameBuffer_Height = this->c_Window_Height;

		Log::Init();

		LOG_E_INFO("====== Starting new instance ======");

		// Set working directory here
		if (m_spec.WorkingDirectory.empty())
		{
			LOG_E_ERROR ("No working directory defined!");
		}

		LOG_E_INFO("Setting working directory to : '{}'", m_spec.WorkingDirectory);

		instance = this;

		// Initialize GLFW
		initGLFW(4, 5, m_spec.Resizable);

		// Initialize the window
		initWindow(m_spec.title, m_spec.Window_Width, m_spec.Window_Height);
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
			LOG_E_DEBUG("GLFW initialization completed.");
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VER_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VER_MINOR);
		glfwWindowHint(GLFW_RESIZABLE, Resizable);

		LOG_E_TRACE("GL_VER_MAJOR is set to : {}", GL_VER_MAJOR);
		LOG_E_TRACE("GL_VER_MINOR is set to : {}", GL_VER_MINOR);
		LOG_E_TRACE("GLFW_RESIZABLE is set to : {}", Resizable);
		LOG_E_INFO("Using OpenGL version {}.{}", GL_VER_MAJOR, GL_VER_MINOR);
	}

	void Application::initWindow(std::string title, int width, int height)
	{
		//INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
		glewExperimental = GL_TRUE;

		if (nullptr == Window)
		{
			Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			LOG_E_INFO("New window resolution : {}x{}", width, height);
		}

		glfwGetFramebufferSize(Window, &FrameBuffer_Width, &FrameBuffer_Height);
		glfwSetFramebufferSizeCallback(Window, framebuffer_resize_callback);

		glfwMakeContextCurrent(Window);

		//Error
		if (glewInit() != GLEW_OK)
		{
			LOG_E_CRITICAL("ERROR! GLEW_INIT_FAILED");
			glfwTerminate();
		}		

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_E_INFO("OpenGL Information :");
		LOG_E_INFO("	{}", glVendor);
		LOG_E_INFO("	{}", glRenderer);
		LOG_E_INFO("	{}", glVersion);

		LOG_E_INFO("====== Instance '{}' created ======", title);

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
