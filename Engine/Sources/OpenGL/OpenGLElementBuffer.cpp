#include "OpenGL/OpenGLElementBuffer.h"

namespace Engine
{
	Ref<OpenGLElementBuffer> OpenGLElementBuffer::Create(std::vector<GLuint>& indices)
	{
		return CreateRef<OpenGLElementBuffer>(indices);
	}

	OpenGLElementBuffer::OpenGLElementBuffer(std::vector<GLuint>& indices)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	}

	OpenGLElementBuffer::~OpenGLElementBuffer()
	{
		glDeleteBuffers(1, &ID);
	}

	// Binds the EBO
	void OpenGLElementBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	// Unbinds the EBO
	void OpenGLElementBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}