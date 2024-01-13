#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>

#include "Core/Logger.h"
//#include "Core/Mesh.h"

#include "Renderer/Primitives.h"
#include "Renderer/Shader.h"

#include "Renderer/Camera.h"

namespace Engine
{
	class OpenGL
	{
	public:
		OpenGL();

		void Set_ClearColor(const glm::vec4& color);

		void Clear();

		//void LoadVBO(std::vector<Vertex*> vertexArray, std::vector<GLuint*> indexArray);

		//void Draw();

		void Shutdown();

	private:
		const char* m_vertexShaderFile = "";
		const char* m_fragmentShaderFile = "";

		GLuint VAO = 0, VBO = 0, EBO = 0;
		unsigned nrOfVertices = 0;
		unsigned nrOfIndices = 0;
	};

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height);
}