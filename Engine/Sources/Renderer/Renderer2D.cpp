#include "Renderer/Renderer2D.h"

// Set Quad vertex position
float QuadVertex[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

unsigned int QuadIndices[] = {
			0, 1, 3,  // first Triangle
			1, 2, 3   // second Triangle
};

namespace Engine
{
	void Renderer2D::Init()
	{
		uint32_t offset = 0;
		for (size_t i = 0; i < (sizeof(QuadVertex) / sizeof(QuadVertex[0])) / 3; i++)
		{
			s_data.QuadVertex.push_back({ QuadVertex[i + 0 + offset], QuadVertex[i + 1 + offset], QuadVertex[i + 2 + offset] });
			offset += 2;
		}

		for (size_t i = 0; i < sizeof(QuadIndices) / sizeof(QuadIndices[0]); i++)
		{
			s_data.QuadIndices.push_back(QuadIndices[i]);
		}

		Instance instance = Instance::GetInstance();

		VAO = instance.GetVAO();
		VBO = instance.GetVBO();
		EBO = instance.GetEBO();

		Shader = instance.GetShader();

		Shader = OpenGLShader::Create("Game/Assets/Shaders/vertex_basic.glsl", "Game/Assets/Shaders/fragment_basic.glsl");

		VAO = OpenGLVertexArray::Create();
		VAO->Bind();
		//VBO = OpenGLVertexBuffer::Create(s_data.QuadVertex);
		VBO = OpenGLVertexBuffer::Create(QuadVertex);
		//EBO = OpenGLElementBuffer::Create(s_data.QuadIndices);
		EBO = OpenGLElementBuffer::Create(QuadIndices);

		// Set position
		VAO->LinkAttribF(0, 3, 3 * sizeof(float), (void*)0);
		// Set color
		//VAO->LinkAttribF(1, 3, sizeof(Vertex), (void*)(3 * sizeof(float)));
		// Set texCoord
		//VAO->LinkAttribF(2, 2, sizeof(Vertex), (void*)(6 * sizeof(float)));

		VBO->Unbind();
		VAO->Unbind();
	}

	void Renderer2D::SetRenderingMode(RenderMode mode)
	{
		switch (mode)
		{
		case Engine::wireframe:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		case Engine::normal:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		default:
			break;
		}
	}

	void Renderer2D::Render()
	{
		Shader->Activate();
		VAO->Bind();
		//sizeof(QuadIndices)
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}