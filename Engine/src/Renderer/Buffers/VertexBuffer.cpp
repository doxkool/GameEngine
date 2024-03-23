#include "Renderer/Buffers/VertexBuffer.h"

#include "Platforms/OpenGL/OpenGLVertexBuffer.h"

namespace Engine
{
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		return CreateRef<OpenGLVertexBuffer>(size);
	}
}