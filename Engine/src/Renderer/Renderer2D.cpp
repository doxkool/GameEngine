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
		shader.Init("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");
	}

	void Renderer2D::CreateTriangle(glm::vec3 position, const char* texturePath)
	{
		Triangle triangle;
		
		model.LoadMesh(triangle, position, texturePath);

	}

	void Renderer2D::CreateQuad(glm::vec3 position, const char* texturePath)
	{
		Quad quad;

		model.LoadMesh(quad, position, texturePath);
		
	}

	void Renderer2D::Render()
	{
		opengl.Set_ClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.f));
		opengl.Clear();

		model.Draw(shader, camera);

		
	}

	void Renderer2D::Shutdown()
	{
		shader.Delete();
	}
}