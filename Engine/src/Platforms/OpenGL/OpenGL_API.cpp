#include "Platforms/OpenGL/OpenGL_API.h"


namespace Engine
{
	void OpenGL_DebugMsgCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         LOG_E_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       LOG_E_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          LOG_E_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: LOG_E_TRACE(message); return;
		}
	}

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height)
	{
		glViewport(0, 0, Window_Width, Window_Height);

		LOG_E_DEBUG("Window resolution changed to : {}x{}", Window_Width, Window_Height);
	};

	void OpenGLAPI::Init()
	{

		//Check GLEW is initialized correctly
		if (glewInit() != GLEW_OK)
		{
			LOG_E_CRITICAL("ERROR! GLEW_INIT_FAILED");
		}
		else {
			LOG_E_DEBUG("GLEW_INIT_SUCCESS");
		}

		#ifdef ENGINE_DEBUG
				glEnable(GL_DEBUG_OUTPUT);
				glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

				glDebugMessageCallback(OpenGL_DebugMsgCallback, nullptr);
		#endif
	}

	void OpenGLAPI::Set_Viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLAPI::Set_ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r , color.g, color.b, color.a);
	}

	void OpenGLAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGLAPI::SwapBuffer()
	{
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		glfwSwapBuffers(window);
	}

	void OpenGLAPI::Shutdown()
	{
		glfwTerminate();
	}
}