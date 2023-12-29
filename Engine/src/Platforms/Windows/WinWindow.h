#pragma once

#include "Platforms/OpenGL/OpenGL_API.h"

#include "Core/Logger.h"

#include "Core/Application.h"


namespace Engine
{
	class WinWindow : public Window
	{
		public:
			WinWindow(const WindowProps& props);
			virtual ~WinWindow();

			static void Render();
			static void Update();

			void SwapBuffer();

			virtual void* GetNativeWindow() const { return m_Window; }

			struct Window_Data
			{
				std::string Title;
				unsigned int Width, Height;
			};

		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();
		private:

			Window_Data m_Data;

			GLFWwindow* m_Window;

			//int FrameBuffer_Width;
			//int FrameBuffer_Height;

			// Get monitor current resolution width
			int max_width = GetSystemMetrics(SM_CXSCREEN);
			
			// Get monitor current resolution hieght
			int max_hieght = GetSystemMetrics(SM_CYSCREEN);

			
	};
}