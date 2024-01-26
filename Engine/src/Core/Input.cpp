#include "Core/Input.h"

namespace Engine
{
	void Input::UpdateInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{

	}

	bool Input::CheckKeyboardInput(int key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS;
	}

	void Input::UpdateMouseInput(GLFWwindow* window)
	{

		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);
	}
}