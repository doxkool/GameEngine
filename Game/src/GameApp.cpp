#include "Engine.h"

#include <Core/EntryPoint.h>

#include "Sandbox.h"


class Game : public Engine::Application
{
public:
	Game(const Engine::AppSpec& specification)
		: Engine::Application(specification)
	{
		new Sandbox();
	}

	~Game()
	{
	}
};


Engine::Application* Engine::CreateApplication(Engine::AppSpec)
{
	AppSpec Spec;
	Spec.title = "Sandbox";
	//Spec.WorkingDirectory = "../Game";
	Spec.Window_Height = 1080;
	Spec.Window_Width = 1920;

	return new Game(Spec);
}