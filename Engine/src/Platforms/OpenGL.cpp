#include "Platforms/OpenGL.h"


namespace Engine
{
	void initGLFW(const int GL_VER_MAJOR, const int GL_VER_MINOR)
	{
		//INIT GLFW
		if (!glfwInit())
		{
			//LOG_E_CRITICAL("ERROR::GLFW_INIT_FAILED");
			glfwTerminate();
		}
		else {
			//LOG_E_TRACE("GLFW_INIT_SUCCESS");
		}

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VER_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VER_MINOR);
	}

	void initWindow(const char *title, int width, int height)
	{
		GLFWwindow* Window = glfwCreateWindow(width, height, title, NULL, NULL);

		glfwMakeContextCurrent(Window);
	}
}