#pragma once

#include "Renderer/Buffers/VertexBuffer.h"

namespace Engine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		//virtual void SetData(const void* data, uint32_t size) override;

	private:
		uint32_t ID;
	};
}