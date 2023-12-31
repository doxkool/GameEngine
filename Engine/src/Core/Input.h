#pragma once

#include "Platforms/Windows/WinWindow.h"

namespace Engine
{
	class Input
	{
	public:
		static void UpdateInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void UpdateKeyboardInput(GLFWwindow* window);
		static void UpdateMouseInput(GLFWwindow* window);

	private:
		
	};
}