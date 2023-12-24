#include "Engine.h"

#include <Core/EntryPoint.h>


class Game : public Engine::Application
{
public:
	Game(const Engine::AppSpec& specification)
		: Engine::Application(specification)
	{
		
	}

	~Game()
	{
	}
};


Engine::Application* Engine::CreateApplication(Engine::AppSpec)
{
	AppSpec Spec;
	Spec.title = "OpenGL";
	Spec.Window_Height = 1080;
	Spec.Window_Width = 1920;
	Spec.Resizable = true;

	return new Game(Spec);
}