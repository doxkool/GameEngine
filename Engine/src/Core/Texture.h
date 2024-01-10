#pragma once

#include "Core/Logger.h"
#include "Renderer/Primitives.h"

#include <GL/glew.h>
#include <stb_image.h>

#include <filesystem>
#include <string>

namespace Engine
{
	class Texture
	{
	public:
		Texture();
		~Texture();

		void LoadTexture(const char* texturePath);

		void BindTexture();

		GLuint ID;

	private:
		
	};
}