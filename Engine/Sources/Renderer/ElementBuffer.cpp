#include "Renderer/ElementBuffer.h"

#include "OpenGL/OpenGLElementBuffer.h"

namespace Engine
{
	Ref<ElementBuffer> ElementBuffer::Create(std::vector<unsigned int>& indices)
	{
		return CreateRef<OpenGLElementBuffer>(indices);
	}
}