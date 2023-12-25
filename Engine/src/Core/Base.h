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
