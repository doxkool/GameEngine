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
		: VAO(0), VBO(0), EBO(0), m_vertexShaderFile(""), m_fragmentShaderFile(""), nrOfVertices(0), nrOfIndices(0)
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

		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);
	}

	void OpenGL::Set_ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGL::LoadVBO(std::vector<Vertex*> vertexArray, std::vector<GLuint*> indexArray)
	{
		this->nrOfVertices = vertexArray.size();
		this->nrOfIndices = indexArray.size();

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices * sizeof(Vertex), vertexArray[0], GL_STATIC_DRAW);

		//GEN EBO AND BIND AND SEND DATA
		if (this->nrOfIndices > 0)
		{
			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->nrOfIndices * sizeof(GLuint), indexArray[0], GL_STATIC_DRAW);
		}

		// SET VERTEXATTRIBPOINTERS AND ENABLE (INPUT ASSEMBLY)
		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);
		// Color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		glEnableVertexAttribArray(1);
		//Texcoord
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));
		glEnableVertexAttribArray(2);
		////Normal
		//glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		//glEnableVertexAttribArray(3);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);
	}

	void OpenGL::Draw()
	{
		glBindVertexArray(VAO);
		if (this->nrOfIndices == 0)
		{
			glDrawArrays(GL_TRIANGLES, 0, this->nrOfVertices);
		}
		else
		{
			glDrawElements(GL_TRIANGLES, this->nrOfIndices, GL_UNSIGNED_INT, 0);
		}
	}

	void OpenGL::Shutdown()
	{
		LOG_E_TRACE("Deleting VAO and VBO buffers...");

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
}