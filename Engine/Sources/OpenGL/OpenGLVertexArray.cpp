#include "OpenGL/OpenGLVertexArray.h"

namespace Engine
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &ID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
	}

	void OpenGLVertexArray::LinkAttribF(GLuint layout, GLuint numComponents, GLsizei stride, void* offset)
	{
		glVertexAttribPointer(layout, numComponents, GL_FLOAT, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(layout);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(ID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}