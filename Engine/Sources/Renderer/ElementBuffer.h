#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class ElementBuffer
	{
	public:
		virtual ~ElementBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<ElementBuffer> Create(std::vector<unsigned int>& indices);
	};
}