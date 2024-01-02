#pragma once

#include "Platforms/OpenGL/OpenGL_Shader.h"

#include "Core/Logger.h"

namespace Engine
{
	std::string get_file_contents(const char* filename);

	class Shader
	{
	public:
		// Constructor that build the Shader Program from 2 different shaders
		Shader();

		unsigned int Shader::LoadShader(const char* vertexFile, const char* fragmentFile);

		// Activates the Shader Program
		void Activate();
		// Deletes the Shader Program
		void Delete();
	private:

		const char* m_VertexFile;
		const char* m_FragmentFile;
	};
}