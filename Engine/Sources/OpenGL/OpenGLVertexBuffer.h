#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class  OpenGLVertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind();
		void Unbind();

		void SetData(const void* data, uint32_t size);

		static Ref<OpenGLVertexBuffer> Create(uint32_t size);
		static Ref<OpenGLVertexBuffer> Create(float* vertices, uint32_t size);

	private:
		uint32_t ID;
	};
}