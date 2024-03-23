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

	void OpenGLVertexArray::LinkAttrib(GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset)
	{
		glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
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