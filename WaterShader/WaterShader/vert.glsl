#version 330 core


layout(location=0) in vec3 vertexPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main (){
		
     mat4 MVP = projection * view * model;
	 gl_Position= MVP * vec4(vertexPosition,1.0f);

}