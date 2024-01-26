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


	class Event
	{
		public:
			virtual ~Event() = default;

			void PushEvent(EventSource source);

		public:
			bool EventHandled;

		private:

			
	};
}