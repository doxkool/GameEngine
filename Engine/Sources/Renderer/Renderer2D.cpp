#include "Renderer/Renderer2D.h"

#include "Core/Instance.h"

namespace Engine
{
	// Set Quad vertex position
	float QuadVertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int QuadIndices[] = {
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	struct QuadVertex {
		glm::vec3 position;
		//glm::vec3 color;
		//glm::vec2 texCoords;
	};

	struct Renderer2DStats
	{
		uint32_t QuadCount = 0;
	};

	struct Renderer2DData
	{
		uint32_t MaxQuads = 100;
		uint32_t MaxVertices = MaxQuads * 4;
		uint32_t MaxIndices = MaxQuads * 6;
		uint32_t MaxTextureSlots = 32;

		glm::vec4 QuadVertexPositions[4];

		std::vector<float> QuadVertices;
		std::vector<unsigned int> QuadIndices;

		uint32_t QuadIndexCount = 0;
		QuadVertex* QuadVertexBufferBase = nullptr;
		QuadVertex* QuadVertexBufferPtr = nullptr;

		Ref<VertexArray> QuadVAO;
		Ref<VertexBuffer> QuadVBO;
		Ref<ElementBuffer> QuadEBO;
		Ref<OpenGLIndexBuffer> QuadIBO;

		Ref<OpenGLTexture> QuadTexture;
		Ref<OpenGLShader> QuadShader;

		Renderer2DStats Stats;
	};

	static Renderer2DData s_data;

	void Renderer2D::Init()
	{
		SetupQuadPtr();
	}

	void Renderer2D::SetupQuadPtr()
	{
	// Pushing the Quad vertices.
		s_data.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
		s_data.QuadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
		s_data.QuadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
		s_data.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };

	// Pushing the Quad indices.
		for (size_t i = 0; i < sizeof(QuadIndices); i++)
		{
			s_data.QuadIndices.push_back(QuadIndices[i]);
		}

		s_data.QuadVertexBufferBase = new QuadVertex[s_data.MaxVertices];

	// Creating basic shader.
		s_data.QuadShader = OpenGLShader::Create("Game/Assets/Shaders/vertex_basic.glsl", "Game/Assets/Shaders/fragment_basic.glsl");

	// Creating default texture.

	// Creating VAO and binding it.
		s_data.QuadVAO = VertexArray::Create();
		s_data.QuadVAO->Bind();

		s_data.QuadVBO = VertexBuffer::Create(s_data.MaxVertices * sizeof(QuadVertex));
		//s_data.QuadVBO->Bind();

	// Creating the VBO and EBO.
		//s_data.QuadVBO = VertexBuffer::Create(s_data.QuadVertices, sizeof(s_data.QuadVertices));
		s_data.QuadEBO = ElementBuffer::Create(s_data.QuadIndices);
		
	// Linking the Quad position to the shader.
		s_data.QuadVAO->LinkAttribF(0, 3, sizeof(QuadVertex), (void*)0);
	// Linking the Quad color to the shader.
			//s_data.QuadVAO->LinkAttribF(1, 3, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Linking the Quad TexCoord to the shader.
			//s_data.QuadVAO->LinkAttribF(2, 2, sizeof(Vertex), (void*)(6 * sizeof(float)));

	// Unbinding VAO and VBO.
		s_data.QuadVAO->Unbind();
		s_data.QuadVBO->Unbind();
	}

	void Renderer2D::SetRenderingMode(int mode)
	{
		switch (mode)
		{
		case 0:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		case 1:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		default:
			LOG_WARN("Rendering mode {} is not valid!", mode);
			break;
		}
	}

	void Renderer2D::DrawQuad(const glm::mat4& transform)
	{
		constexpr size_t quadVertexCount = 4;

		s_data.QuadVertexBufferPtr = s_data.QuadVertexBufferBase;

		for (size_t i = 0; i < quadVertexCount; i++)
		{
			s_data.QuadVertexBufferPtr->position = transform * s_data.QuadVertexPositions[i];
			//s_data.QuadVertexBufferPtr->color = color;
			//s_data.QuadVertexBufferPtr->texCoords = textureCoords[i];
			//s_data.QuadVertexBufferPtr->TexIndex = textureIndex;
			//s_data.QuadVertexBufferPtr->TilingFactor = tilingFactor;
			s_data.QuadVertexBufferPtr++;
		}

		s_data.QuadIndexCount += 6;

		s_data.Stats.QuadCount++;
	}

	void Renderer2D::Render()
	{
		uint32_t dataSize = (uint32_t)((uint8_t*)s_data.QuadVertexBufferPtr - (uint8_t*)s_data.QuadVertexBufferBase);
		s_data.QuadVBO->SetData(s_data.QuadVertexBufferBase, dataSize);

		s_data.QuadShader->Activate();
		s_data.QuadVAO->Bind();

		uint32_t count = s_data.QuadIndexCount ? s_data.QuadIndexCount : s_data.QuadVAO->GetIndexBuffer()->GetCount();

		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
		
		//OpenGL::Render(s_data.QuadVAO, sizeof(s_data.QuadIndices));
	}
}