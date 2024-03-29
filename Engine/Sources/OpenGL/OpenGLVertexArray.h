#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"

#include <glm.hpp>

namespace Engine
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 texCoords;
	};

	class OpenGLVertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		// Links a VBO Attribute such as a position or color to the VAO
		void LinkAttribF(GLuint layout, GLuint numComponents, GLsizei stride, void* offset);

		void Bind();
		void Unbind();

		//void AddVertexBuffer(OpenGLVertexBuffer& VBO);
		//void SetIndexBuffer(const OpenGLIndexBuffer& indexBuffer);

		static Ref<OpenGLVertexArray> Create();

	private:
		uint32_t ID;

	};
}