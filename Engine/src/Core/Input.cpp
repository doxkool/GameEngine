#include "Core/Input.h"

namespace Engine
{
	void Input::UpdateInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		UpdateKeyboardInput(window);
		UpdateMouseInput(window);
	}

	void Input::UpdateKeyboardInput(GLFWwindow* window)
	{

		//Camera
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			//camera.move(dt, FORWARD);
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			//camera.move(dt, BACKWARD);
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			//camera.move(dt, LEFT);
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			//camera.move(dt, RIGHT);
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			//camera.move(dt, UP);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		{
			//camera.move(dt, DOWN);
		}

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			
		}
	}

	void Input::UpdateMouseInput(GLFWwindow* window)
	{

		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);
	}
}