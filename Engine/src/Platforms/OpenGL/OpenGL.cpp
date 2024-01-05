#include "Platforms/OpenGL/OpenGL.h"

namespace Engine
{
	void OpenGL_DebugMsgCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         LOG_E_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       LOG_E_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          LOG_E_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: LOG_E_TRACE(message); return;
		}
	}

	void framebuffer_resize_callback(GLFWwindow* Window, int Window_Width, int Window_Height)
	{
		glViewport(0, 0, Window_Width, Window_Height);

		LOG_E_DEBUG("Window resolution changed to : {}x{}", Window_Width, Window_Height);
	};

	OpenGL::OpenGL()
	{
		//Check GLEW is initialized correctly
		if (glewInit() != GLEW_OK)
		{
			LOG_E_CRITICAL("ERROR! GLEW_INIT_FAILED");
		}
		else {
			LOG_E_DEBUG("GLEW_INIT_SUCCESS");
		}

		#ifdef ENGINE_DEBUG
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		
			glDebugMessageCallback(OpenGL_DebugMsgCallback, nullptr);
		#endif
	}

	std::string OpenGL::ReadShaderFile(const char* ShaderFile)
	{
		std::string temp = "";
		std::string src = "";

		std::ifstream in_file;

		//Vertex
		in_file.open(ShaderFile);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
				src += temp + "\n";
		}
		else
		{
			LOG_E_ERROR("ERROR::SHADER::COULD_NOT_OPEN_FILE: {}", ShaderFile);
		}

		in_file.close();

		return src;
	}

	void OpenGL::LoadShaders(const char* vertexShaderFile, const char* fragmentShaderFile)
	{
		m_vertexShaderFile = vertexShaderFile;
		m_fragmentShaderFile = fragmentShaderFile;

		std::string str_src;
		const GLchar* src;

		// build and compile our shader program
		// ------------------------------------
		// vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		str_src = this->ReadShaderFile(m_vertexShaderFile);
		src = str_src.c_str();
		glShaderSource(vertexShader, 1, &src, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		str_src = this->ReadShaderFile(m_fragmentShaderFile);
		src = str_src.c_str();
		glShaderSource(fragmentShader, 1, &src, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		// link shaders
		m_shaderProgram = glCreateProgram();
		glAttachShader(m_shaderProgram, vertexShader);
		glAttachShader(m_shaderProgram, fragmentShader);
		glLinkProgram(m_shaderProgram);
		// check for linking errors
		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGL::Set_ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGL::LoadVBO(std::vector<Vertex> vertexArray)
	{
		float vertices[] = {
			// positions         // colors
			 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
			 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

	unsigned int OpenGL::Get_ShaderProgram()
	{
		return m_shaderProgram;
	}

	void OpenGL::Draw(unsigned int shaderProgram)
	{
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void OpenGL::Shutdown()
	{
		LOG_E_DEBUG("Closing OpenGL_API...");

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(m_shaderProgram);
	}
}