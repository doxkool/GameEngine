#pragma once

#include "OpenGL/OpenGL.h"

#include <glfw3.h>

#include <vector>
#include <math.h>
#include <stdio.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Engine
{
	class ImGuiLayer
	{
	public:
		ImGuiLayer() {}

		static void Init(GLFWwindow* window);
		static void NewFrame();
		static void Render();

		static void ShowMenuBar();
		static void ShowStatistics();
		static void ShowAdvanceStatistics();


		static bool b_ShowStatistics;
		static bool b_ShowAdvanceStatistics;
		static bool b_ShowMenuBar;
		//static bool b_ShowSceneInspector;

		static bool b_ShowDemoWindow;

	private:

		//static std::vector<Base_Entity> m_Entity_Data;

		static std::vector<float> FrameTime;
		static std::vector<float> FPS;
	};
}