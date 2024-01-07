#include "Renderer/Renderer2D.h"

namespace Engine
{
	Renderer2D::Renderer2D()
	{
	}

	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::Init()
	{
		opengl.LoadShaders("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

		ShaderProgram = opengl.Get_ShaderProgram();
	}

	void Renderer2D::CreateTriangle()
	{
		Triangle triangle;

		std::vector<Engine::Vertex*> Vertices;
		std::vector<GLuint*> Indices;

		for (size_t i = 0; i < triangle.getNrOfVertices(); i++)
		{
			Vertices.push_back(&triangle.getVertices()[i]);
		}

		for (size_t i = 0; i < triangle.getNrOfIndices(); i++)
		{
			Indices.push_back(&triangle.getIndices()[i]);
		}

		opengl.LoadVBO(Vertices, Indices);
	}

	void Renderer2D::CreateQuad()
	{
		Quad quad;
		
		std::vector<Engine::Vertex*> Vertices;
		std::vector<GLuint*> Indices;
		
		for (size_t i = 0; i < quad.getNrOfVertices(); i++)
		{
			Vertices.push_back(&quad.getVertices()[i]);
		}
		
		for (size_t i = 0; i < quad.getNrOfIndices(); i++)
		{
			Indices.push_back(&quad.getIndices()[i]);
		}

		opengl.LoadVBO(Vertices, Indices);
	}

	void Renderer2D::Render()
	{
		opengl.Set_ClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.f));
		opengl.Clear();
		opengl.Draw(ShaderProgram);
	}
}