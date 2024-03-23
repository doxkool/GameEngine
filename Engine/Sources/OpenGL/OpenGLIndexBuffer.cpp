#include "OpenGL/OpenGLIndexBuffer.h"

namespace Engine
{
	Ref<OpenGLIndexBuffer> OpenGLIndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		return CreateRef<OpenGLIndexBuffer>(indices, size);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
		: m_Count(count)
	{
		glCreateBuffers(1, &m_RendererID);

		// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
		// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	//OpenGLIndexBuffer::Create(uint32_t* indices, uint32_t count)
	//{
	//	glCreateBuffers(1, &m_RendererID);
	//
	//	// GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
	//	// Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state. 
	//	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	//	glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	//}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}