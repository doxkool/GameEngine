#pragma once

#include "Engine.h"

#include "Core\Application.h"

extern Engine::Application* Engine::CreateApplication(AppSpec);

int main()
{
	Engine::AppSpec Spec;
	auto app = Engine::CreateApplication(Spec);
	app->Run();
	delete app;

	LOG_G_DEBUG("Closing NOW");
}