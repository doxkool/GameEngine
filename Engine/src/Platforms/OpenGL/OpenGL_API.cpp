#include "Platforms/OpenGL/OpenGL_API.h"


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

	void OpenGL_API::Init()
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

	void OpenGL_API::Set_Viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGL_API::Set_ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r , color.g, color.b, color.a);
	}

	void OpenGL_API::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	//void OpenGL_API::Draw(Shader shaderProgram)
	//{
	//	glUseProgram(shaderProgram);
	//	glBindVertexArray(VAO);
	//	glDrawArrays(GL_TRIANGLES, 0, 3);
	//}

	void OpenGL_API::SwapBuffer()
	{
		Application& application = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(application.GetWindow().GetNativeWindow());

		glfwSwapBuffers(window);
		glFlush();
	}

	//unsigned int OpenGL_API::LoadShaders()
	//{
	//	OpenGL_Shader GL_Shader_Inst("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");
	//
	//	return GL_Shader_Inst.Get_ShaderProgram();
	//}

	unsigned int OpenGL_API::LoadVerticesBuffer()
	{
		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		return VAO;
	}

	void OpenGL_API::Draw(unsigned int shaderProgram)
	{
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void OpenGL_API::Shutdown()
	{
		LOG_E_DEBUG("Closing OpenGL_API...");

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(m_shaderProgram);
	}
}