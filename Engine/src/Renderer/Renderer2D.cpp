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

	void Renderer2D::CreateTriangle(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, const char* texturePath)
	{
		Triangle triangle;
		
		model.LoadMesh(triangle, translation, rotation, scale, texturePath);

	}

	void Renderer2D::CreateQuad(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale,  const char* texturePath)
	{
		Quad quad;

		model.LoadMesh(quad, translation, rotation, scale, texturePath);
		
	}

	void Renderer2D::UpdateTransform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
	{

	}

	void Renderer2D::UpdateTexture(const char* texturePath)
	{

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