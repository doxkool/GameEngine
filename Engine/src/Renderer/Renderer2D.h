#pragma once

#include "Platforms/OpenGL/OpenGL.h"

#include "Renderer/Primitives.h"

namespace Engine
{
	class Renderer2D
	{
	public:
		Renderer2D();
		~Renderer2D();

		void Init();

		void CreateTriangle();
		void CreateQuad();

		void Render();

	private:
		Engine::OpenGL opengl;
		unsigned int ShaderProgram;

	};
}