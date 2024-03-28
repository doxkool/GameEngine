#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
//layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
//layout (location = 2) in vec2 aTexCoord;

// Outputs the current position for the Fragment Shader
//out vec3 crntPos;
//out vec3 ourColor; // output a color to the fragment shader
//out vec2 TexCoord;

//uniform mat4 camera;
//uniform mat4 model;
//uniform mat4 world;

void main()
{
	// calculates current position
	//crntPos = vec3(model * world * vec4(aPos, 1.0f));
    
    //ourColor = aColor; // set ourColor to the input color we got from the vertex data

	//TexCoord = aTexCoord;

	//gl_Position = camera * vec4(crntPos, 1.0);
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}  