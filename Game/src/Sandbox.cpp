#include "Sandbox.h"

Sandbox::Sandbox()
{
	LOG_G_INFO("Starting Sandbox...");
	Engine::WinWindow::EnableVsync(1);
}