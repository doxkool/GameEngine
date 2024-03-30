#pragma once

#include "Core/Base.h"

#include <vector>

namespace Engine
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetData(const void* data, uint32_t size) = 0;

		static Ref<VertexBuffer> Create(uint32_t size);
		static Ref<VertexBuffer> Create(std::vector<float>& vertices, uint32_t size);
		static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
	};
}