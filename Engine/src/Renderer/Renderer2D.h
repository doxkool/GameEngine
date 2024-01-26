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
	class Renderer2D
	{
	public:
		Renderer2D();

		static void DrawTriangle(glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture texture = Texture("Engine/Default_Tex.jpg"));
		static void DrawQuad(glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), Texture texture = Texture("Engine/Default_Tex.jpg"));

		static void Shutdown();

	private:
		static unsigned int ShaderProgram;

	};
}