#pragma once

#include "Platforms/OpenGL/OpenGL.h"

#include "Renderer/Shader.h"
#include "Renderer/Primitives.h"

namespace Engine
{
	class Renderer2D
	{
	public:
		Renderer2D();
		~Renderer2D();

		void Init(Camera* camera);

		void CreateTriangle();
		void CreateQuad();

		void Render();

		void Shutdown();

	private:
		OpenGL opengl;
		Shader shader;
		Camera* camera;
		unsigned int ShaderProgram;

	};
}