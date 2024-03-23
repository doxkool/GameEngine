#pragma once

#include "Engine.h"

#include "Core/Instance.h"

extern Engine::Instance* Engine::CreateInstance(InstanceSpec);

int main()
{
	Engine::InstanceSpec Spec;

	auto instance = Engine::CreateInstance(Spec);
	instance->Run();
	delete instance;

	Engine::LOG_DEBUG("Closing NOW");
}