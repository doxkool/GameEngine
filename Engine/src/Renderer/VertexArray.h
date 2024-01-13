#pragma once

#include "Renderer/VertexBuffer.h"

#include <GL/glew.h>


namespace Engine
{
	class VertexArray
	{
	public:
		VertexArray();

		// Links a VBO Attribute such as a position or color to the VAO
		void LinkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
		// Binds the VAO
		void Bind();
		// Unbinds the VAO
		void Unbind();
		// Deletes the VAO
		void Delete();

		// ID reference for the Vertex Array Object
		GLuint ID;

	private:

	};
}