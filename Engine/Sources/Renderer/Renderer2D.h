#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/ElementBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"

namespace Engine
{
	class Renderer2D
	{
		public:

			static void Init();

			static void SetRenderingMode(int mode);

			static void DrawQuad(const glm::mat4& transform);

			static void Render();

		private:
			static void SetupQuadPtr();
	};
}