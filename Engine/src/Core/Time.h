#pragma once

#include "Platforms/OpenGL/OpenGL_API.h"

namespace Engine {

	class Time
	{
	public:
		// Return glfwGetTime()
		static float GetTime() { return glfwGetTime(); }
	};

	class TimeStep
	{
	public:
		
		TimeStep(float time = 0.0f)
			: m_Time(time)
		{}

		operator float() const { return m_Time; }

		float Get_Seconds() const { return m_Time; }
		float Get_Milliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}