#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class OpenGLShader
	{
	public:
		OpenGLShader(const char* vertexShaderFile = NULL, const char* fragmentShaderFile = NULL);
		~OpenGLShader();

		void LoadShader(const char* vertexShaderFile, const char* fragmentShaderFile);
		void Activate();
		void Delete();

		void set1i(GLint value, const GLchar* name);
		void set1f(GLfloat value, const GLchar* name);
		void setVec2f(glm::fvec2 value, const GLchar* name);
		void setVec3f(glm::fvec3 value, const GLchar* name);
		void setVec4f(glm::fvec4 value, const GLchar* name);
		void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE);
		void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);

		int GetID();

		static Ref<OpenGLShader> Create(const char* vertexShaderFile, const char* fragmentShaderFile);

	private:
		std::string ReadShaderFile(const char* ShaderFile);

		uint32_t ID;
	};
}