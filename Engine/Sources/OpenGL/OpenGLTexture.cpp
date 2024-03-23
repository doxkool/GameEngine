#define STB_IMAGE_IMPLEMENTATION

#include "OpenGL/OpenGLTexture.h"

#include <GL/glew.h>

namespace Engine
{
	Ref<OpenGLTexture> OpenGLTexture::Create(const std::string& texPath)
	{
		return CreateRef<OpenGLTexture>(texPath);
	}

	OpenGLTexture::OpenGLTexture(const std::string& texPath)
	{
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;

		if (texPath.c_str())
		{
			unsigned char* data = stbi_load(texPath.c_str(), &width, &height, &nrChannels, 0);
			if (data)
			{
				if (nrChannels == 3)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				}
				if (nrChannels == 4)
				{
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				}

				glGenerateMipmap(GL_TEXTURE_2D);
				LOG_TRACE("Texture loaded : {}", texPath);
			}
			else
			{
				LOG_ERROR("Failed to load texture : {}", texPath);

				stbi_image_free(data);
				unsigned char* data = stbi_load("Game/Textures/Default_Tex.jpg", &width, &height, &nrChannels, 0);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			stbi_image_free(data);
		}
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &ID);
	}

	void OpenGLTexture::texUnit(const char* uniform, unsigned int unit)
	{
		// Gets the location of the uniform
		//GLuint texUni = glGetUniformLocation(Shader::GetID(), uniform);
		// Shader needs to be activated before changing the value of a uniform
		//Shader::Activate(); 
		// Sets the value of the uniform
		//glUniform1i(texUni, unit);
	}

	void OpenGLTexture::BindTexture(uint32_t slot)
	{
		glBindTextureUnit(slot, ID);
	}
}