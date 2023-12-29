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

	class Perf
	{
		public:
			void StartTime(float start_time){ m_Frames++; m_Start_Time = start_time; }

			void EndTime(){ m_End_Time = m_Start_Time; m_Frames = 0; }

			float Get_FPS(){ return (m_Frames / (m_Start_Time - m_End_Time)); }

			float Get_FrameTime(){ return ((m_Start_Time - m_End_Time) * 1000); }

		private:
			float m_Start_Time = 0.0;
			float m_End_Time = 0.0;
			int m_Frames = 0;

			float FPS = 0.0;
			float MS = 0.0;
	};

}