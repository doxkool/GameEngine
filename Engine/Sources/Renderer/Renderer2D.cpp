#include "Renderer/Renderer2D.h"

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

namespace Engine
{
	void Renderer2D::Init()
	{
		std::vector<unsigned int> indices;
		for (size_t i = 0; i < sizeof(QuadIndices); i++)
		{
			indices.push_back(QuadIndices[i]);
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
		VBO = OpenGLVertexBuffer::Create(QuadVertices, sizeof(QuadVertices));
		//EBO = OpenGLElementBuffer::Create(s_data.QuadIndices);
		EBO = OpenGLElementBuffer::Create(indices);

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
		glDrawElements(GL_TRIANGLES, sizeof(QuadIndices), GL_UNSIGNED_INT, 0);
	}
}