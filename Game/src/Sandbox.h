#pragma once

#include "Engine.h"

class Sandbox
{
	public:
		Sandbox();
		virtual ~Sandbox() = default;

		void OnUpdate(Engine::TimeStep ts);

	private:

		//Engine::Ref<Engine::Shader> m_DefaultShader;

};