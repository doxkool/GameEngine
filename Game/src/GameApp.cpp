#include "Engine.h"

#include <Core/EntryPoint.h>

#include "Sandbox.h"


class Game : public Engine::Application
{
public:
	Game(const Engine::AppSpec& specification)
		: Engine::Application(specification)
	{
		PushLayer(new Sandbox());
	}

	~Game()
	{
	}
};


Engine::Application* Engine::CreateApplication(Engine::AppSpec)
{
	AppSpec Spec;
	Spec.title = "Engine Debug";
	Spec.WorkingDirectory = "../Game";
	Spec.Window_Height = 1000;
	Spec.Window_Width = 1000;

	return new Game(Spec);
}