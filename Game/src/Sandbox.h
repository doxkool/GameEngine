#pragma once

#include "Engine.h"

class Sandbox : public Engine::Layer
{
	public:
		Sandbox();
		virtual ~Sandbox() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Engine::TimeStep ts) override;

	private:

		Engine::OpenGL opengl;
		unsigned int ShaderProgram;

};