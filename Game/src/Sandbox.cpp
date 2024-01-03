#include "Sandbox.h"

Sandbox::Sandbox()
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	//Engine::WinWindow::EnableVsync(1);
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	
}