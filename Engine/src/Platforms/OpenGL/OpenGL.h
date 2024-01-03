#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Core/Logger.h"

namespace Engine
{
	class OpenGL
	{
	public:
		OpenGL(const char* vertexShaderFile, const char* fragmentShaderFile);
		virtual ~OpenGL();

		std::string ReadShaderFile(const char* ShaderFile);

		void LoadShaders();

		void Set_ClearColor(const glm::vec4& color);

		void Clear();

		unsigned int LoadVerticesBuffer();

		void Draw(unsigned int shaderProgram);

		unsigned int Get_ShaderProgram();

		void Shutdown();

	private:
		const char* m_vertexShaderFile;
		const char* m_fragmentShaderFile;

		unsigned int m_shaderProgram;
		unsigned int VAO, VBO;

	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}