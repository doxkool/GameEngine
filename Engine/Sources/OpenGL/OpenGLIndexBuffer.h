#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class OpenGLIndexBuffer
	{
	public:
		OpenGLIndexBuffer() = default;
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		void Bind();
		void Unbind();

		uint32_t GetCount() const { return m_Count; }

		static Ref<OpenGLIndexBuffer> Create(uint32_t* indices, uint32_t size);

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}