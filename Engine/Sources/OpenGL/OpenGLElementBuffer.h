#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class OpenGLElementBuffer
	{
	public:
		OpenGLElementBuffer(std::vector<unsigned int>& indices);
		OpenGLElementBuffer(unsigned int* indices);
		~OpenGLElementBuffer();

		// Binds the EBO
		void Bind();
		// Unbinds the EBO
		void Unbind();

		static Ref<OpenGLElementBuffer> Create(std::vector<unsigned int>& indices);
		static Ref<OpenGLElementBuffer> Create(unsigned int* indices);

	private:
		// ID reference of Elements Buffer Object
		GLuint ID;

	};
}