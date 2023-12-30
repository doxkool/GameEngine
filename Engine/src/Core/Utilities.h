#pragma once
#include "Core/Time.h"

namespace Engine
{
	class Perf
	{
	public:
		// Run this at the START of what you want to monitor.
		void StartPerfCounter() { m_Frames++; m_Start_Time = Time::GetTime(); }
		// Run this at the END of what you want to monitor.
		void EndPerfCounter() { m_End_Time = m_Start_Time; m_Frames = 0; }

		double Get_FPS() { return (m_Frames / (m_Start_Time - m_End_Time)); }

		double Get_FrameTime() { return ((m_Start_Time - m_End_Time) * 1000); }

	private:
		float m_Start_Time = 0.0;
		float m_End_Time = 0.0;
		int m_Frames = 0;
	};
}