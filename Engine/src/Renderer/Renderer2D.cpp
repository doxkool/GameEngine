#include "Renderer/Renderer2D.h"

// TODO :

namespace Engine
{
	struct QuadVertex
	{
		glm::vec3 Position;
		glm::vec4 Color;
		glm::vec2 TexCoord;

		int EntityID;
	};

	struct Renderer2D_Data
	{
		static const uint32_t MaxQuads = 20000;
		static const uint32_t MaxVertices = MaxQuads * 4;
		static const uint32_t MaxIndices = MaxQuads * 6;
		static const uint32_t MaxTextureSlots = 32; // TODO: RenderCaps

		Ref<VertexArray> QuadVertexArray;
		Ref<VertexBuffer> QuadVertexBuffer;
		Ref<Shader> QuadShader;
		Ref<Texture> QuadTexture;

		uint32_t QuadIndexCount = 0;
		QuadVertex* QuadVertexBufferBase = nullptr;
		QuadVertex* QuadVertexBufferPtr = nullptr;

		uint32_t TextureSlotIndex = 1;

		glm::vec4 QuadVertexPositions[4];
	};

	static Renderer2D_Data s_Data;

	void Renderer2D::Init()
	{
		s_Data.QuadVertexArray = VertexArray::Create();
		s_Data.QuadVertexBuffer = VertexBuffer::Create(s_Data.MaxVertices * sizeof(QuadVertex));

		//s_Data.QuadShader = Shader::Create("assets/shaders/Renderer2D_Quad.glsl");
	}

	void Renderer2D::DrawTriangle(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture texture)
	{
		//Triangle triangle;
		
		//Model::LoadMesh(triangle, translation, rotation, scale, texture);

	}

	void Renderer2D::DrawQuad(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture texture)
	{
		//Quad quad;

		//Model::LoadMesh(quad, translation, rotation, scale, texture);
		
	}

	void Renderer2D::Shutdown()
	{
		Shader::Delete();
	}
}