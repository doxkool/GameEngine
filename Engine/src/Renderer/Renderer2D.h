#pragma once

#include "Core/Base.h"

#include "Core/Model.h"
#include "Core/Mesh.h"
#include "Core/Texture.h"

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
		~Renderer2D();

		void Init();

		void CreateTriangle(glm::vec3 position, const char* texturePath);
		void CreateQuad(glm::vec3 position, const char* texturePath);

		void Render();

		void Shutdown();

	private:
		OpenGL opengl;
		Shader shader;
		Model model;
		Camera camera;
		unsigned int ShaderProgram;

	};
}