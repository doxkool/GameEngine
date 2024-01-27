#include "Platforms/Windows/WinWindow.h"


namespace Engine
{
	static void GLFWErrorCallback(int error, const char* message)
	{
		LOG_E_ERROR("GLFW Error ({}): {}", error, message);
	}

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height)
	{
		OpenGL::SetViewport(Window_Width, Window_Height);

		LOG_E_DEBUG("Window resolution changed to : {}x{}", Window_Width, Window_Height);
	};

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

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_E_INFO("OpenGL_API Information :");
		LOG_E_INFO("	{}", glVendor);
		LOG_E_INFO("	{}", glRenderer);
		LOG_E_INFO("	{}", glVersion);

		LOG_E_INFO("====== Instance '{}' created ======", m_Data.Title);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Setting up GLFW callback for keyboard and mouse events
		glfwSetKeyCallback(m_Window, Key_Callback);
		glfwSetScrollCallback(m_Window, Mouse_Scroll_Callback);
		glfwSetMouseButtonCallback(m_Window, Mouse_Button_Callback);
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

	void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input::UpdateKeyboardInput(window, key, scancode, action, mods);
	}

	void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		
	}

	void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
	{

	}
}