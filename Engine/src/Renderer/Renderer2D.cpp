#include "Renderer/Renderer2D.h"

// TODO :

namespace Engine
{
	Renderer2D::Renderer2D()
	{
	
	}

	void Renderer2D::DrawTriangle(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture texture)
	{
		Triangle triangle;
		
		Model::LoadMesh(triangle, translation, rotation, scale, texture);

	}

	void Renderer2D::DrawQuad(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, Texture texture)
	{
		Quad quad;

		Model::LoadMesh(quad, translation, rotation, scale, texture);
		
	}

	void Renderer2D::Shutdown()
	{
		Shader::Delete();
	}
}