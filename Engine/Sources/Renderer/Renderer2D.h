#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/ElementBuffer.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"

namespace Engine
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 texCoords;
	};

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

		std::vector<float> QuadVertices;
		std::vector<unsigned int> QuadIndices;

		Ref<VertexArray> QuadVAO;
		Ref<VertexBuffer> QuadVBO;
		Ref<ElementBuffer> QuadEBO;

		Ref<OpenGLTexture> QuadTexture;
		Ref<OpenGLShader> QuadShader;
	};

	class Renderer2D
	{
		public:

			void Init();

			void SetupQuad();

			void SetRenderingMode(RenderMode mode);

			void Render();

		private:
			Renderer2DData s_data;
	};
}