#include "Renderer/RendererCMD.h"

// TODO :

namespace Engine
{
	RendererCMD::RendererCMD()
	{
	
	}

	void RendererCMD::LoadShader(const char* vertexFile, const char* fragmentFile)
	{
		OpenGL::Init();
		Shader::Init(vertexFile, fragmentFile);
	}

	Texture RendererCMD::LoadTexture(const char* texturePath)
	{
		Texture texture(texturePath);

		return texture;
	}

	void RendererCMD::Set_ClearColor(glm::vec4 color)
	{
		OpenGL::Set_ClearColor(color);
	}

	void RendererCMD::Clear()
	{
		OpenGL::Clear();
	}

	void RendererCMD::Render(Camera camera)
	{
		Model::Draw(camera);
	}
}