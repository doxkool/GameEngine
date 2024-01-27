#pragma once

#define GLEW_STATIC

#include "Core/Logger.h"

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{
	class OpenGL
	{
	public:
		static void Init();

		static void SetViewport(int Window_Width, int Window_Height);

		static int GetViewport() { return Viewport_Width, Viewport_Height;}

		static void Set_ClearColor(const glm::vec4& color);

		static void Clear();

	public:
		static int Viewport_Width, Viewport_Height;

	};
}