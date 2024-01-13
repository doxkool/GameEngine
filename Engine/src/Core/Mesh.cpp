#include "Core/Mesh.h"

namespace Engine
{
	Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
	{
		Mesh::vertices = vertices;
		Mesh::indices = indices;
		Mesh::textures = textures;

		VAO.Bind();
		// Generates Vertex Buffer Object and links it to vertices
		VertexBuffer VBO(vertices);
		// Generates Element Buffer Object and links it to indices
		ElementBuffer EBO(indices);

		// Links VBO Position attributes to VAO
		VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		// Links VBO Color attributes to VAO
		VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		// Links VBO Texcoord attributes to VAO
		VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		// Links VBO Normal attributes to VAO
		VAO.LinkAttrib(VBO, 3, 3, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

		// Unbind all to prevent accidentally modifying them
		VAO.Unbind();
		VBO.Unbind();
		EBO.Unbind();
	}

	// TODO : Be able to load mesh from file.
	//Mesh::Mesh(Vertex* vertices, GLuint* indices, Texture* textures)
	//{
	//	VAO.Bind();
	//	// Generates Vertex Buffer Object and links it to vertices
	//	VertexBuffer VBO(vertices);
	//	// Generates Element Buffer Object and links it to indices
	//	ElementBuffer EBO(indices);
	//	// Links VBO attributes such as coordinates and colors to VAO
	//	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	//	VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	//	VAO.LinkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
	//	// Unbind all to prevent accidentally modifying them
	//	VAO.Unbind();
	//	VBO.Unbind();
	//	EBO.Unbind();
	//}

	// TODO : Use this function, not use at the moment.
	void Mesh::updateModelMatrix()
	{
		this->ModelMatrix = glm::mat4(1.f);
		this->ModelMatrix = glm::translate(this->ModelMatrix, this->origin);
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.x), glm::vec3(1.f, 0.f, 0.f));
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.y), glm::vec3(0.f, 1.f, 0.f));
		this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.z), glm::vec3(0.f, 0.f, 1.f));
		this->ModelMatrix = glm::translate(this->ModelMatrix, this->position - this->origin);
		this->ModelMatrix = glm::scale(this->ModelMatrix, this->scale);
	}

	// TODO : Finish this function
	void Mesh::Draw
	(
		Shader& shader,
		Camera& camera
		)
		//glm::mat4 matrix,
		//glm::vec3 translation,
		//glm::quat rotation,
		//glm::vec3 scale
		//)
	{
		// Bind shader to be able to access uniforms
		shader.Activate();
		VAO.Bind();

		for (unsigned int i = 0; i < textures.size(); i++)
		{
			//textures[i].texUnit(shader, (type + num).c_str(), i);
			textures[i].BindTexture();
		}

		// Take care of the camera Matrix
		//glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		camera.Matrix(&shader, "camMatrix");

		// Initialize matrices
		//glm::mat4 trans = glm::mat4(1.0f);
		//glm::mat4 rot = glm::mat4(1.0f);
		//glm::mat4 sca = glm::mat4(1.0f);

		// Transform the matrices to their correct form
		//trans = glm::translate(trans, translation);
		//rot = glm::mat4_cast(rotation);
		//sca = glm::scale(sca, scale);

		// Push the matrices to the vertex shader
		//glUniformMatrix4fv(glGetUniformLocation(shader.ID, "translation"), 1, GL_FALSE, glm::value_ptr(trans));
		//glUniformMatrix4fv(glGetUniformLocation(shader.ID, "rotation"), 1, GL_FALSE, glm::value_ptr(rot));
		//glUniformMatrix4fv(glGetUniformLocation(shader.ID, "scale"), 1, GL_FALSE, glm::value_ptr(sca));
		//glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(matrix));

		// Draw the actual mesh
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}
}