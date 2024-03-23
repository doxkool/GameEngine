#pragma once

#include "OpenGL/OpenGL.h"

#include "OpenGL/OpenGLWindow.h"

#include "ImGui/ImGuiLayer.h"

namespace Engine
{
	class OpenGLInput
	{
	public:
		static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void Mouse_Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);
		static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);

		static bool IsKeyPressed(GLFWwindow* window, int key);

	private:

	};
}