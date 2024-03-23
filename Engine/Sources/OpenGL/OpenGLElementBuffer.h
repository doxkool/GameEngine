#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class OpenGLElementBuffer
	{
	public:
		OpenGLElementBuffer(std::vector<GLuint>& indices);
		~OpenGLElementBuffer();

		// Binds the EBO
		void Bind();
		// Unbinds the EBO
		void Unbind();

		static Ref<OpenGLElementBuffer> Create(std::vector<GLuint>& indices);

	private:
		// ID reference of Elements Buffer Object
		GLuint ID;

	};
}