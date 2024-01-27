#include "Core/Input/Input.h"

namespace Engine
{
	void Input::UpdateKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{

	}

	void Input::UpdateMouseScrollInput(GLFWwindow* window, double xoffset, double yoffset)
	{

	}

	void Input::UpdateMouseButtonInput(GLFWwindow* window, int button, int action, int mods)
	{

	}

	bool Input::CheckKeyboardInput(KeyCode key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, key);
		return state == GLFW_PRESS;
	}

	bool Input::CheckMouseButtonInput(MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}
}