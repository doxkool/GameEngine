#pragma once

#include "OpenGL/OpenGL.h"

#include <stb_image.h>

#include <filesystem>

namespace Engine
{
	class OpenGLTexture
	{
	public:
		OpenGLTexture(const std::string& texPath);
		~OpenGLTexture();

		void texUnit(const char* uniform, unsigned int unit);

		void BindTexture(uint32_t slot);

		static Ref<OpenGLTexture> Create(const std::string& texPath);

		uint32_t ID;

	private:
	};
}