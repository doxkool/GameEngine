#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Core/Logger.h"
//#include "Core/Mesh.h"

#include "Renderer/Primitives.h"

namespace Engine
{
	//struct Vertex {
	//	glm::vec3 position;
	//	glm::vec3 color;
	//	//glm::vec2 texcoord;
	//	//glm::vec3 normal;
	//};

	class OpenGL
	{
	public:
		OpenGL();

		std::string ReadShaderFile(const char* ShaderFile);

		void LoadShaders(const char* vertexShaderFile, const char* fragmentShaderFile);

		void Set_ClearColor(const glm::vec4& color);

		void Clear();

		void LoadVBO(std::vector<Vertex*> vertexArray, std::vector<GLuint*> indexArray);

		void Draw(unsigned int shaderProgram);

		void CreateQuad();

		unsigned int Get_ShaderProgram();

		void Shutdown();

	private:
		const char* m_vertexShaderFile;
		const char* m_fragmentShaderFile;

		GLuint m_shaderProgram;
		GLuint VAO, VBO, EBO;
		unsigned nrOfVertices;
		unsigned nrOfIndices;
	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}