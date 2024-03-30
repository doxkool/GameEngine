#pragma once

#include "Renderer/ElementBuffer.h"

namespace Engine
{
	class OpenGLElementBuffer : public ElementBuffer
	{
	public:
		OpenGLElementBuffer(std::vector<unsigned int>& indices);
		//OpenGLElementBuffer(unsigned int* indices);
		virtual ~OpenGLElementBuffer();

		// Binds the EBO
		virtual void Bind() const override;
		// Unbinds the EBO
		virtual void Unbind() const override;

	private:
		// ID reference of Elements Buffer Object
		GLuint ID;

	};
}