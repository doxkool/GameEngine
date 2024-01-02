#include "Renderer/Shader.h"

namespace Engine
{
	// Reads a text file and outputs a string with everything in the text file
	std::string get_file_contents(const char* filename)
	{
		std::ifstream in(filename, std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return(contents);
		}
		throw(errno);
	}

	// Constructor that build the Shader Program from 2 different shaders
	Shader::Shader()
	{
		
	}

	unsigned int Shader::LoadShader(const char* vertexFile, const char* fragmentFile)
	{
		OpenGL_Shader GL_Shader(m_VertexFile, m_FragmentFile);

		return GL_Shader.Get_ShaderProgram();
	}

	// Activates the Shader Program
	void Shader::Activate()
	{
		
	}

	// Deletes the Shader Program
	void Shader::Delete()
	{
		
	}
}