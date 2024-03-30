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

	void Renderer2D::Init()
	{
		SetupQuad();
	}

	void Renderer2D::SetupQuad()
	{
		// Pushing the Quad vertices.
		for (size_t i = 0; i < sizeof(QuadVertices); i++)
		{
			s_data.QuadVertices.push_back(QuadVertices[i]);
		}

		// Pushing the Quad indices.
		for (size_t i = 0; i < sizeof(QuadIndices); i++)
		{
			s_data.QuadIndices.push_back(QuadIndices[i]);
		}

		// Creating basic shader.
		s_data.QuadShader = OpenGLShader::Create("Game/Assets/Shaders/vertex_basic.glsl", "Game/Assets/Shaders/fragment_basic.glsl");

		// Creating default texture.

		// Creating VAO and binding it.
		s_data.QuadVAO = VertexArray::Create();
		s_data.QuadVAO->Bind();

		// Creating the VBO and EBO.
		s_data.QuadVBO = VertexBuffer::Create(s_data.QuadVertices, sizeof(s_data.QuadVertices));
		s_data.QuadEBO = ElementBuffer::Create(s_data.QuadIndices);

		// Linking the Quad position to the shader.
		s_data.QuadVAO->LinkAttribF(0, 3, 3 * sizeof(float), (void*)0);
		// Linking the Quad color to the shader.
			//s_data.QuadVAO->LinkAttribF(1, 3, sizeof(Vertex), (void*)(3 * sizeof(float)));
		// Linking the Quad TexCoord to the shader.
			//s_data.QuadVAO->LinkAttribF(2, 2, sizeof(Vertex), (void*)(6 * sizeof(float)));

		// Unbinding VAO and VBO.
		s_data.QuadVAO->Unbind();
		s_data.QuadVBO->Unbind();
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
		s_data.QuadShader->Activate();

		s_data.QuadVAO->Bind();
		glDrawElements(GL_TRIANGLES, sizeof(s_data.QuadIndices), GL_UNSIGNED_INT, 0);
		
		//OpenGL::Render(s_data.QuadVAO, sizeof(s_data.QuadIndices));
	}
}