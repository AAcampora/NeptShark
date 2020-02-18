#version 330 core 

//** required a output value for binding with fragment 
uniform vec3 MyVariable;
in vec4 vertexColourOut;


out vec4 colour;
in vec4 myVariable;
void main()
{
	colour = vertexColourOut;
}