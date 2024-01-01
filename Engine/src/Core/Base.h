#pragma once

#include "Core/OSDetection.h"

#include <memory>

#ifdef ENGINE_DEBUG
	#if defined(ENGINE_PLATFORM_WINDOWS)
		#define ENGINE_DEBUGBREAK() __debugbreak()
	#endif
#else
	#define ENGINE_DEBUGBREAK()
#endif

namespace Engine
{
	template<typename T>
	using Pointer = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Pointer<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
