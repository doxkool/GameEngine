#pragma once

#include "Core/Base.h"

#include "Core/Application.h"
#include "Core/Model.h"
#include "Core/Mesh.h"
#include "Core/Texture.h"
#include "Core/Input.h"

#include "Platforms/OpenGL/OpenGL.h"

#include "Renderer/Shader.h"
#include "Renderer/Primitives.h"

// TODO : this is temporary
#include "Core/Window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Engine
{
	class RendererCMD
	{
	public:
		RendererCMD();

		static void LoadShader(const char* vertexFile, const char* fragmentFile);

		static Texture LoadTexture(const char* texturePath = "Engine/Default_Tex.jpg");

		static void Set_ClearColor(glm::vec4 color = glm::vec4(0.f, 0.f, 0.f, 0.f));
		static void Clear();

		static void Render(Camera camera);

	private:
		static unsigned int ShaderProgram;

	};
}