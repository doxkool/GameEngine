#pragma once

#include "Engine.h"

class Sandbox : public Engine::Layer
{
public:
	Sandbox();
	virtual ~Sandbox();

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Engine::TimeStep ts) override;

private:
	Engine::Renderer2D renderer2D;
	
};