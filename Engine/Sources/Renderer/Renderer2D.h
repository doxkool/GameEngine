#pragma once

#include "Core/Base.h"

#include "Core/Instance.h"

#include "OpenGL/OpenGL.h"
#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLElementBuffer.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"

namespace Engine
{
	enum RenderMode
	{
		wireframe,
		normal
	};

	struct Renderer2DData
	{
		uint32_t MaxQuads = 10;
		uint32_t MaxVertices = MaxQuads * 4;
		uint32_t MaxIndices = MaxQuads * 6;
		uint32_t MaxTextureSlots = 32;

		std::vector<Vertex>* QuadVertices = nullptr;

		std::vector<glm::vec3> QuadVertex;
		std::vector<unsigned int> QuadIndices;
	};

	class Renderer2D
	{
		public:

			void Init();

			void SetRenderingMode(RenderMode mode);

			void Render();

		private:
			Renderer2DData s_data;

			Ref<OpenGLVertexArray> VAO;
			Ref<OpenGLVertexBuffer> VBO;
			Ref<OpenGLElementBuffer> EBO;

			Ref<OpenGLShader> Shader;
	};
}