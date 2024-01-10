#define STB_IMAGE_IMPLEMENTATION

#include "Core/Texture.h"

namespace Engine
{
	Texture::Texture()
	{
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, this->ID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);
	}

	Texture::~Texture()
	{
	}

	void Texture::LoadTexture(const char* texturePath)
	{
		int width, height, nrChannels;
		
		unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			LOG_E_TRACE("Texture loaded : {}", texturePath);
		}
		else
		{
			LOG_E_ERROR("Failed to load texture");
		}
		stbi_image_free(data);
	}

	void Texture::BindTexture()
	{
		glBindTexture(GL_TEXTURE_2D, this->ID);
	}
}