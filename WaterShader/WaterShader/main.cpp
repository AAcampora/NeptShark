
//* the entry point of my application *//


#include "main.h"  //include the main header


//create a pointer to our window
SDL_Window* window = nullptr;
	
int main(int argc, char* args[]) 
{				
	GLuint VertexArrayID = 0; //we name Our VAO
	GLuint triangleVerBuff = 0;//then we pass our triangle to be worked by open gl, we do this by creating a buffer accordingly

	//initalise our consturctor
	NeptShark Nept(&window);
	//** Buffer Section **//
	Nept.VertexSetup(VertexArrayID);
	
	//load our shader programs
	GLint basicProgramID = MyShaderCreator::LoadShaders("vert.glsl", "frag.glsl");
	if (basicProgramID < 0)
	{
		printf("Shaders %s and %s not loaded", "vert.glsl", "frag.glsl");
	}


	//triangle buffer TODO ask brian how to extrapolate this
	static const GLfloat g_vertex_buffer_data[] = { //this will buff the position of the vertixes on the window
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	glGenBuffers(1, &triangleVerBuff); //we create a buffer, and we store our triangle ID

	glBindBuffer(GL_ARRAY_BUFFER, triangleVerBuff); //then we bind it as a vertex buffer

	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW); //now we pass the vertices of our triangle to opengl
	//for the drawing of our triangle, go look the render section
	
	SimpleCamera cam(basicProgramID);
														//** Main Game Loop Section **//


	//first thing first, we create a boolean that stores our main game loop
	bool running = true;
	//SDl event structure, this is a queue that contains all the event strutctures of library, it can read the events and place them in itself
	//useful when you need to determinate a certain event.
	SDL_Event ev;
	while (running)
	{
		//pool for the events which have happend in this frame
			//remember SDL_PollEvent requires a pointer value&
		while (SDL_PollEvent(&ev))
		{
			//switch statement for any kind of message the event gives us
			switch (ev.type)
			{
				//quit message, called when the window is closed
			case SDL_QUIT:
				running = false;
				break;
				//KEYDOWN message, called when a key has been pressed down
			case SDL_KEYDOWN:
				//check if a key has been pressed trough ev
				switch (ev.key.keysym.sym)
				{
					//check if it was the escape key
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_F4:
					if (!Nept.fullscreen)
					{

						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
						Nept.fullscreen = true;
						/*if (Nept.fullscreen)
						{
							SDL_SetWindowFullscreen(window, 0);
							Nept.fullscreen = false;
						}*/
					}
					
					
				}

			}
		}
								 									//** Render Section **//
		Nept.SetColors();
		//draw using this program
		glUseProgram(basicProgramID);

		//send constant uniforms to shader 
		cam.GenCameraUniforms();

		Nept.RenderTriangle(triangleVerBuff);

		//update our window now
		//remember. all the rendering behind this.
		SDL_GL_SwapWindow(window);

	}

														//** Garbage Collection Section **//
	//Destoy the window and quit SDL2, clean all the things you have created
	glDeleteProgram(basicProgramID);
	glDeleteBuffers(1, &triangleVerBuff);
	glDeleteVertexArrays(1, &VertexArrayID); //delete the VAO

	SDL_DestroyWindow(window); 
	SDL_Quit();

	return 0;
}
