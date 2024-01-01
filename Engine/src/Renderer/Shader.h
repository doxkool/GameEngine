#pragma once
#include "Core/Base.h"

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

namespace Engine
{
	class Shader
	{
		public:
			virtual ~Shader() = default;

			//virtual void Bind() const = 0;
			//virtual void Unbind() const = 0;

			static Ref<Shader> CreateVertexShader(const std::string& filepath);
			static Ref<Shader> CreateFragmentShader(const std::string& filepath);

		private:

	};
}