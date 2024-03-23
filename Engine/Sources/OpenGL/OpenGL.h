#pragma once

#include "Core/Base.h"
#include "Core/Logger.h"

#include <glm.hpp>
#include <gtc/type_ptr.hpp>

#include <string>
#include <vector>


#include <GL/glew.h>
#include <glfw3.h>

namespace Engine
{
	class OpenGL
	{
	public:
		static void Init();

		static void Set_ClearColor(const glm::vec4& color);
		static void Clear();
		static void SetViewport(int FrameBuffer_Width, int FrameBuffer_Height);

	public:
		static int m_FrameBuffer_Width, m_FrameBuffer_Height;

	private:

	};
}