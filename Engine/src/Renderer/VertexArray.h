#pragma once

#include "Core/Base.h"

#include "Renderer/Buffers/VertexBuffer.h"

#include <GL/glew.h>


namespace Engine
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<VertexArray> Create();
	};
}