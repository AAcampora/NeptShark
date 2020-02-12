#include "NeptShark.h"



NeptShark::NeptShark(SDL_Window** window)
{
	//for sdl Initialisation, please see SDL_Initialiser.h
	int SDLInitialiser();

	//for the Window initialisation, please see WindowSpawner.h
	WindowInit::WindowSpawner(window);

	//for Glew Initialisation, please see Glew initialiser.h//
	GlewInit::GlewInitialiser(window);

}


void NeptShark::VertexSetup(GLuint vertexArrayID)
{
	//where we load our objects TODO class loading program for this
	glGenVertexArrays(1, &vertexArrayID); //this returns an n VAO names in Array, and garants that those names are not the same as the ones called before the function
	glBindVertexArray(vertexArrayID); //bind the VAO we are returning from glGenVertexArrays
}

void NeptShark::SetColors()
{

	//set the colour of the screen
	glClearColor(0.0, 0.0, 0.4, 0.0);
	//set the bitplane area of the window using our colour buffer
	glClear(GL_COLOR_BUFFER_BIT);
}

void NeptShark::RenderTriangle(GLuint triangleVerBuff)
{
	//we enable our vertex array. we do this because by default all all client-side capabilities are disabled, including all generic vertex attribute arrays.
		//if enabled we can make calls regarding rendering and allow us to draw
	glEnableVertexAttribArray(0);

	//we now get our triangle buffer and move it here for drawing //remember, once bind to a new object, this buffer previous contract is broken
	glBindBuffer(GL_ARRAY_BUFFER, triangleVerBuff);

	//now we specify the location and the type of attributes of our buffer
	glVertexAttribPointer(
		0,					//INDEX, it's used to specify the vertex attribute that needs to be modified
		3,					//SIZE, used to understeand the number of components per generic vertex attribute
		GL_FLOAT,			//TYPE, used to determine the type of our components per generic vertex attribute
		GL_FALSE,			//NORMALIZED, Specifies whether fixed-point data values should be normalized or converted directly as fixed-point values.
		0,					//STRIDE, specifies the byte offest between consecutive generic vertex attributes. If this is 0, it means that the arrays are packed thightly togherter
		(void*)0			//POINTER, this points to the first componnent of the first generic vertex attribute. The initial value is 0
	);

	//now that we have our buffer attributes settled, we can finally draw our triangle

	glDrawArrays(GL_TRIANGLES, 0, 3); //specifies what kidn of primitives to renderd. we provide a starting index, then we provide with the number of vertices
	glDisableVertexAttribArray(0); //we now disable our ability to draw, so we don't draw anything else unecessary.
}
