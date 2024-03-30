#pragma once

#include "Renderer/VertexArray.h"

#include <glm.hpp>

namespace Engine
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		// Links a VBO Attribute such as a position or color to the VAO
		virtual void LinkAttribF(GLuint layout, GLuint numComponents, GLsizei stride, void* offset) override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const Ref<OpenGLIndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		uint32_t ID;

		Ref<OpenGLIndexBuffer> m_IndexBuffer;
	};
}