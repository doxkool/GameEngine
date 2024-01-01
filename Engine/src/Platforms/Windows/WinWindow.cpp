#include "Platforms/Windows/WinWindow.h"


namespace Engine
{
	static void GLFWErrorCallback(int error, const char* message)
	{
		LOG_E_ERROR("GLFW Error ({}): {}", error, message);
	}

	WinWindow::WinWindow(const WindowProps& props)
	{
		Init(props);
	}

	WinWindow::~WinWindow()
	{
		Shutdown();
	}
	
	void WinWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;

		glfwSetErrorCallback(GLFWErrorCallback);
		
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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_RESIZABLE, true);

		glewExperimental = GL_TRUE;
		
		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		glfwSetWindowMonitor(m_Window, NULL, (max_width / 2) - (m_Data.Width / 2), (max_hieght / 2) - (m_Data.Height / 2), m_Data.Width, m_Data.Height, GLFW_DONT_CARE);
		LOG_E_INFO("New window resolution : {}x{}", m_Data.Width, m_Data.Height);
		
		glfwSetFramebufferSizeCallback(m_Window, framebuffer_resize_callback);

		glfwMakeContextCurrent(m_Window);

		OpenGL_API::Init();

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_E_INFO("OpenGL Information :");
		LOG_E_INFO("	{}", glVendor);
		LOG_E_INFO("	{}", glRenderer);
		LOG_E_INFO("	{}", glVersion);

		LOG_E_INFO("====== Instance '{}' created ======", m_Data.Title);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetKeyCallback(m_Window, key_callback);

	}

	void WinWindow::Shutdown()
	{
		LOG_E_DEBUG("Clossing WinWindow...");
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WinWindow::Update()
	{
		glfwPollEvents();
	}

	void WinWindow::Render()
	{
		OpenGL_API::Set_ClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.f));
		OpenGL_API::Clear();
		//OpenGL_API::Draw();

		SwapBuffer();
	}

	void WinWindow::SwapBuffer()
	{
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		glfwSwapBuffers(window);
	}

	// Enable or disable Vsync : 1 = true or 0 = false
	void WinWindow::EnableVsync(int enabled)
	{
		glfwSwapInterval(enabled);
		LOG_E_DEBUG("vSync set to : {}", enabled);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input::UpdateInput(window, key, scancode, action, mods);
	}
}