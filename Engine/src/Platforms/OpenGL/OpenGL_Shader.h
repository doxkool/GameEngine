#pragma once


namespace Engine
{
	class OpenGL_Shader
	{
		public:
			OpenGL_Shader(const char* vertexFile, const char* fragmentFile);
			virtual ~OpenGL_Shader();

			unsigned int Get_ShaderProgram();


		private:
			const char* m_VertexFile;
			const char* m_FragmentFile;

			unsigned int m_ShaderProgram;
	};
}