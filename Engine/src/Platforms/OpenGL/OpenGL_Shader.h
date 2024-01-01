#pragma once

#include "Renderer/Shader.h"

#include <glm/glm.hpp>

#include <GL/glew.h>

typedef unsigned int GLenum;

namespace Engine
{
	class OpenGL_Shader : public Shader
	{
		public:
			OpenGL_Shader(const GLenum type, const std::string& filepath);
			virtual ~OpenGL_Shader();

			//virtual void Bind() const override;
			//virtual void Unbind() const override;

		private:
			std::string loadShaderFile();
			GLuint CreateShaderProgram(GLenum type);
			void linkProgram(GLuint shader);

			uint32_t m_RendererID;
			std::string m_FilePath;
	};
}