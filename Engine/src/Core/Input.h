#pragma once

#include "Core/Events.h"
#include "Platforms/Windows/WinWindow.h"

#include "Renderer/Camera.h"

namespace Engine
{
	class Input
	{
	public:

		static void UpdateInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		static bool CheckKeyboardInput(int key);
		static void UpdateMouseInput(GLFWwindow* window);
	};
}