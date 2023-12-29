#include "Core/Base.h"
#include "Core/Window.h"

#ifdef ENGINE_PLATFORM_WINDOWS
#include "Platforms/Windows/WinWindow.h"
#endif

namespace Engine
{
	Pointer<Window> Window::Create(const WindowProps& props)
	{
#ifdef ENGINE_PLATFORM_WINDOWS
		return CreateScope<WinWindow>(props);
#else
		LOG_E_ERROR("Unknown platform!");
		return nullptr;
#endif
	}

}