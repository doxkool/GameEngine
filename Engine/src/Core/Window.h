#pragma once

#include "Core/Logger.h"

#include <sstream>

namespace Engine {

	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "OpenGL_API Engine",
			uint32_t width = 1000,
			uint32_t height = 1000)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:

		virtual ~Window() = default;

		//virtual void OnUpdate() = 0;

		//virtual uint32_t GetWidth() const = 0;
		//virtual uint32_t GetHeight() const = 0;

		// Window attributes

		virtual void* GetNativeWindow() const = 0;

		static Pointer<Window> Create(const WindowProps& props = WindowProps());
	};

}