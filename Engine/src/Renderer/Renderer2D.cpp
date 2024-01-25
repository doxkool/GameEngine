#include "Renderer/Renderer2D.h"

// TODO :
// - Convert everything to static.

namespace Engine
{
	Renderer2D::Renderer2D()
	{
	
	}

	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::LoadShader(const char* vertexFile, const char* fragmentFile)
	{
		OpenGL::Init();
		Shader::Init(vertexFile, fragmentFile);
	}

	Texture Renderer2D::LoadTexture(const char* texturePath)
	{
		Texture texture(texturePath);

		return texture;
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

	void Renderer2D::UpdateTransform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
	{

	}

	void Renderer2D::UpdateTexture(const char* texturePath)
	{

	}

	void Renderer2D::Set_ClearColor(glm::vec4 color)
	{
		OpenGL::Set_ClearColor(color);
	}

	void Renderer2D::Clear()
	{
		OpenGL::Clear();
	}

	void Renderer2D::Render(Camera camera)
	{
		Model::Draw(camera);
	}

	void Renderer2D::Shutdown()
	{
		Shader::Delete();
	}
}