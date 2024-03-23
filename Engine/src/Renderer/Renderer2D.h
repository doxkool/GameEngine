#pragma once

#include "Core/Base.h"

#include "Core/Application.h"
#include "Renderer/Model.h"
#include "Renderer/Mesh.h"
#include "Renderer/Texture.h"
#include "Core/Input/Input.h"

#include "Platforms/OpenGL/OpenGL.h"

#include "Renderer/Shader.h"
#include "Renderer/Primitives.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Engine
{
	class Renderer2D
	{
	public:
		static void Init();

		static void DrawTriangle(glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture texture = Texture("Engine/Default_Tex.jpg"));
		static void DrawQuad(glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture texture = Texture("Engine/Default_Tex.jpg"));

		static void Shutdown();

	private:
		static unsigned int ShaderProgram;

	};
}