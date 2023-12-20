#pragma once

#include <glew.h>
#include <glfw3.h>

namespace Engine
{
	// Functions
	void initGLFW(const int GL_VER_MAJOR, const int GL_VER_MINOR);
	void initWindow(const char* title, int width, int height);
	void update();
	void render();
}