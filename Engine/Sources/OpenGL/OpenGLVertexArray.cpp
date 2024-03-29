#include "OpenGL/OpenGLVertexArray.h"

namespace Engine
{
	Ref<OpenGLVertexArray> OpenGLVertexArray::Create()
	{
		return CreateRef<OpenGLVertexArray>();
	}

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

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(ID);
	}

	void OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}