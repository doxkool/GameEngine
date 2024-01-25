#pragma once

#include <vector>

namespace Engine
{
	enum EventSource {
		NONE,
		APPLICATION,
		INPUT, 
		KEYBOARD
	};

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};


	class Events
	{
		public:
			Events();

			void PushEvent(EventSource source);

		public:
			bool EventHandled;

		private:

			
	};
}