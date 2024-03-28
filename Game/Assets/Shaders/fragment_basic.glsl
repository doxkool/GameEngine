#version 330 core
out vec4 FragColor;  
//in vec3 ourColor;
//in vec2 TexCoord;

//uniform sampler2D ourTexture;
  
void main()
{
	//vec4 texColor = texture(ourTexture, TexCoord);
	//
	//if(texColor.a < 0.1)
	//{
	//	discard;
	//}
	//
	//FragColor = texColor;

	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}