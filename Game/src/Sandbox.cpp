#include "Sandbox.h"

// TODO :
// - Expose inputs via abstraction layer to the application.
// - Be able the position objects on screen.

Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	Engine::Camera camera;

	instance.Init(&camera);

	instance.CreateQuad();
}

Sandbox::~Sandbox()
{
	instance.Shutdown();
}


void Sandbox::OnAttach()
{
	
}

void Sandbox::OnDetach()
{
	
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	instance.Render();
}