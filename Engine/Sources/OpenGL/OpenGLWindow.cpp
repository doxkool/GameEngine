#include "OpenGL/OpenGLWindow.h"

namespace Engine
{
	void OpenGLWindow::SetWindow(const std::string Window_Title, const int Window_Width, const int Window_Height, const bool Window_Resizeable)
	{
		WinParams.Window_Title = Window_Title;
		WinParams.Window_Width = Window_Width;
		WinParams.Window_Height = Window_Height;
		WinParams.Window_Resizeable = Window_Resizeable;

		glfwSetErrorCallback(WindowCallback::GLFWErrorCallback);

		//INIT GLFW
		if (!glfwInit())
		{
			LOG_CRITICAL("ERROR::GLFW_INIT_FAILED");
			glfwTerminate();
		}
		else {
			LOG_DEBUG("GLFW initialization completed.");
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_RESIZABLE, true);

		m_Window = glfwCreateWindow(WinParams.Window_Width, WinParams.Window_Height, WinParams.Window_Title.c_str(), NULL, NULL);

		glfwSetWindowMonitor(m_Window, NULL, (GetSystemMetrics(SM_CXSCREEN) / 2) - (WinParams.Window_Width / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (WinParams.Window_Height / 2), WinParams.Window_Width, WinParams.Window_Height, GLFW_DONT_CARE);
		LOG_INFO("New window resolution : {}x{}", WinParams.Window_Width, WinParams.Window_Height);

		glfwMakeContextCurrent(m_Window);

		std::string glVendor = std::string((const char*)glGetString(GL_VENDOR));
		std::string glRenderer = std::string((const char*)glGetString(GL_RENDERER));
		std::string glVersion = std::string((const char*)glGetString(GL_VERSION));

		LOG_INFO("OpenGL_API Information :");
		LOG_INFO("	{}", glVendor);
		LOG_INFO("	{}", glRenderer);
		LOG_INFO("	{}", glVersion);

		LOG_INFO("====== Instance '{}' created ======", WinParams.Window_Title);

		OpenGL::m_FrameBuffer_Width = Window_Width;
		OpenGL::m_FrameBuffer_Height = Window_Height;

	}

	void OpenGLWindow::DetectMonitors()
	{
		// TODO : THIS MAKE THE APPLICATION CRASH
		int numOfMonitor;
		GLFWmonitor* PrimaryMonitor = glfwGetPrimaryMonitor();
		GLFWmonitor** monitors = glfwGetMonitors(&numOfMonitor);

		for (int i = 0; i < numOfMonitor; i++)
		{
			MonitorsSpec[i].MonitorID = i;
			MonitorsSpec[i].MonitorName = glfwGetMonitorName(PrimaryMonitor);
		}
	}

	void OpenGLWindow::SetWindowUserPointer(OpenGLWindow window)
	{
		glfwSetWindowUserPointer(m_Window, &window);
	}

	void OpenGLWindow::UpdateWindowTitle(const std::string NewWindowTitle)
	{
		glfwSetWindowTitle(m_Window, NewWindowTitle.c_str());
	}

	void OpenGLWindow::Update()
	{
		glfwPollEvents();
	}

	void OpenGLWindow::SwapBuffer()
	{
		glfwSwapBuffers(m_Window);
	}

	void OpenGLWindow::EnableVsync(int enabled)
	{
		glfwSwapInterval(enabled);

		LOG_DEBUG("vSync set to : {}", enabled);
	}

	int OpenGLWindow::Get_WindowShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void OpenGLWindow::Set_WindowShouldClose()
	{
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
	}

	bool OpenGLWindow::CheckKeyboardInput(uint16_t key)
	{
		auto state = glfwGetKey(m_Window, key);
		return state;
	}

	bool OpenGLWindow::CheckMouseButtonInput(uint16_t button)
	{
		auto state = glfwGetMouseButton(m_Window, button);
		return state;
	}

	glm::vec2 OpenGLWindow::GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(m_Window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float OpenGLWindow::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float OpenGLWindow::GetMouseY()
	{
		return GetMousePosition().y;
	}

	WindowCallback::WindowCallback(OpenGLWindow& window)
	{
		auto m_Window = window.GetNativeWindow();

		glfwSetKeyCallback(m_Window, OpenGLInput::Key_Callback);
		glfwSetKeyCallback(m_Window, OpenGLInput::Key_Callback);
		glfwSetScrollCallback(m_Window, OpenGLInput::Mouse_Scroll_Callback);
		glfwSetMouseButtonCallback(m_Window, OpenGLInput::Mouse_Button_Callback);

		glfwSetMonitorCallback(MonitorCallback);
		glfwSetWindowSizeCallback(m_Window, WindowResizeCallback);
		glfwSetFramebufferSizeCallback(m_Window, FramebufferResizeCallback);
		glfwSetWindowPosCallback(m_Window, WindowPositionCallback);
		glfwSetWindowMaximizeCallback(m_Window, WindowMaximizeCallback);
	}

	void WindowCallback::GLFWErrorCallback(int error, const char* message)
	{
		LOG_ERROR("GLFW Error ({}): {}", error, message);
	}

	void WindowCallback::MonitorCallback(GLFWmonitor* monitor, int event)
	{
		if (event == GLFW_CONNECTED)
		{
			LOG_TRACE("A New monitor connected...");
		}
		else if (event == GLFW_DISCONNECTED)
		{
			LOG_TRACE("A monitor has been disconnected...");
		}
	}

	void WindowCallback::WindowResizeCallback(GLFWwindow* window, int Window_Width, int Window_Height)
	{

	};

	void WindowCallback::FramebufferResizeCallback(GLFWwindow* window, int FrameBuffer_Width, int FrameBuffer_Height)
	{
		OpenGL::SetViewport(FrameBuffer_Width, FrameBuffer_Height);

		LOG_DEBUG("FrameBuffer resolution changed to : {}x{}", FrameBuffer_Width, FrameBuffer_Height);
	};

	void WindowCallback::WindowPositionCallback(GLFWwindow* window, int xPos, int yPos)
	{
		WindowCallback* state = static_cast<WindowCallback*>(glfwGetWindowUserPointer(window));
	};

	void WindowCallback::WindowMaximizeCallback(GLFWwindow* window, int maximized)
	{
		if (maximized)
		{
			LOG_DEBUG("Window : maximized.");
		}
		else
		{
			LOG_DEBUG("Window : not maximized.");
		}
	};
}