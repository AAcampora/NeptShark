#version 330 core 

//** required a output value for binding with fragment 

in vec4 myVariable;
in vec4 vertexColourOut;
in vec2 vertexTexCoordOut;

uniform sampler2D baseTexture;
uniform vec3 MyVariable;

out vec4 colour;

void main()
{
	 colour = texture(baseTexture,vertexTexCoordOut);
}