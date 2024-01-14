#include "Core/Model.h"


namespace Engine
{
	Model::Model()
	{
	}

	void Model::LoadMesh(const Primitive& primitive, glm::vec3 translation, const char* texturePath)
	{
		I_primitive = primitive;

		std::vector<Vertex> vertexArray;
		std::vector <GLuint> indexArray;
		std::vector <Texture> textureArray;
		std::vector <glm::vec3> translationArray;

		unsigned nrOfVertices;
		unsigned nrOfIndices;

		LOG_E_TRACE("Loading model from primitive...");

		this->vertices = vertices;

		nrOfVertices = I_primitive.getNrOfVertices();
		nrOfIndices = I_primitive.getNrOfIndices();

		//vertexArray = new Vertex[nrOfVertices];
		for (size_t i = 0; i < nrOfVertices; i++)
		{
			vertexArray.push_back(I_primitive.getVertices()[i]);
		}

		//indexArray = new GLuint[nrOfIndices];
		for (size_t i = 0; i < nrOfIndices; i++)
		{
			indexArray.push_back(I_primitive.getIndices()[i]);
		}

		Texture texture(texturePath);

		textureArray.push_back(texture);

		translationArray.push_back(translation);

		meshes.push_back(Mesh(translationArray, vertexArray, indexArray, textureArray));
	}

	void Model::Draw(Shader& shader, Camera& camera)
	{
		// Go over all meshes and draw each one
		for (unsigned int i = 0; i < meshes.size(); i++)
		{
			//meshes[i].Mesh::Draw(shader, camera, matricesMeshes[i]);
			meshes[i].Mesh::Draw(shader, camera);
		}
	}
}