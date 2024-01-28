#pragma once

#include "Events/Event.h"
#include "Platforms/Windows/WinWindow.h"

#include "Renderer/Camera/Camera.h"

#include "Core/Input/KeyCodes.h"
#include "Core/Input/MouseCodes.h"

namespace Engine
{
	class Input
	{
	public:

		static void UpdateKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void UpdateMouseScrollInput(GLFWwindow* window, double xoffset, double yoffset);
		static void UpdateMouseButtonInput(GLFWwindow* window, int button, int action, int mods);

		static bool CheckKeyboardInput(KeyCode key);
		static bool CheckMouseButtonInput(MouseCode button);

		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

	private:
		
	};
}