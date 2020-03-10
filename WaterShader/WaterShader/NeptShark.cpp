 #include "NeptShark.h"


using namespace Nept;

basicRender::basicRender()
{
	//for sdl Initialisation, please see SDL_Initialiser.h
	InitLibs libsInit;
	libsInit.SDLInit();
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	InitWindow(&window);
	libsInit.GlewInit(&window);


}

void basicRender::InitWindow(SDL_Window **window)
{
	

	//this function creates and stores a pointer to a Window. It takes a Title, a position of the window, the dimensions and the flags of how it's displayed
	*window = SDL_CreateWindow("SDL2 Alessio's Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);

	//check if the window is created, remeber to always check if everything has been created
	if (window == nullptr)	//if the window exist, it would be stored in memory, check if the window exist in memory
	{
		//show a message 
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window has failed", SDL_GetError(), NULL);

		//Close the library 
		SDL_Quit();
		//Close the application
	}
	return;
}

basicRender::~basicRender()
{
	//Destoy the window and quit SDL2, clean all the things you have created
	glDeleteProgram(basicProgramID);
	glDeleteBuffers(1, &triangleVerBuff);
	glDeleteVertexArrays(1, &VertexArrayID); //delete the VAO
	glDeleteBuffers(1, &elementBuffer);
	glDeleteTextures(1, &baseTextureID);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void basicRender::MainLoop()
{

	//** Buffer Section **//
	VertexSetup(VertexArrayID);

	//load our shader programs
	GLint basicProgramID = ShaderLoader::LoadShaders("TextureVert.glsl", "TextureFrag.glsl");
	if (basicProgramID < 0)
	{
		printf("Shaders %s and %s not loaded", "TextureVert.glsl", "TextureFrag.glsl");
	}

	//triangle buffer TODO ask brian how to extrapolate this
	Vertex verticies[] =
	{ //this will buff the position of the vertixes on the window
		{1.0f, -1.0f, 0.0f, 1.0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f}, //vertex 0
		{1.0f, 1.0f, 0.0f, 0.0, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f}, //vertex 1
		{-1.0f, 1.0f, 0.0f, 0.0f, 0.0f,1.0f, 1.0f, 0.0f, 1.0f},// vertex 2
		{-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,1.0f, 1.0f, 1.0f, 1.0f} // vertex 3
	};
	

	glGenBuffers(1, &triangleVerBuff); //we create a buffer, and we store our triangle ID
	Factory::createBuffer(2, triangleVerBuff, 4 * sizeof(Vertex), verticies, GL_STATIC_DRAW);

	int indicies[] = { 0, 1, 2, 2, 3 ,0 };

	glGenBuffers(1, &elementBuffer);
	Factory::createBuffer(1, elementBuffer, 4 * sizeof(indicies), indicies, GL_STATIC_DRAW);

	SimpleCamera cam(basicProgramID);

	GLuint baseTextureLocation = glGetUniformLocation(basicProgramID, "baseTexture");

	GLuint baseTextureID = loadTextureFromFile("Crate.jpg");
	//SDl event structure, this is a queue that contains all the event strutctures of library, it can read the events and place them in itself
	//useful when you need to determinate a certain event.
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

				}

			}
		}

		SetColors();
		//draw using this program
		glActiveTexture(GL_TEXTURE0);
 		glBindTexture(GL_TEXTURE_2D, baseTextureID);
		
		//start using the program we made
		glUseProgram(basicProgramID);

		//send constant uniforms to shader 
		cam.GenCameraUniforms();

		glUniform1i(baseTextureLocation, 0);

		RenderObject(triangleVerBuff);


		//update our window now
		//remember. all the rendering behind this.
		SDL_GL_SwapWindow(window);
	}
	basicRender::~basicRender();
}

void basicRender::VertexSetup(GLuint VertexArrayID)
{
	//where we load our objects TODO class loading program for this
	glGenVertexArrays(1, &VertexArrayID); //this returns an n VAO names in Array, and garants that those names are not the same as the ones called before the function
	glBindVertexArray(VertexArrayID); //bind the VAO we are returning from glGenVertexArrays
}

void basicRender::SetColors()
{

	//set the colour of the screen
	glClearColor(0.0, 0.0, 0.4, 0.0);
	//set the bitplane area of the window using our colour buffer
	glClear(GL_COLOR_BUFFER_BIT);
}

void basicRender::RenderObject (GLuint triangleVerBuff)
{
	////we enable our vertex array. we do this because by default all all client-side capabilities are disabled, including all generic vertex attribute arrays.
	//	//if enabled we can make calls regarding rendering and allow us to draw
	//draw the verticies of the object 
	Factory::createVertAttrib(1, 0, 3, sizeof(Vertex), (void*)0 );
	//https://en.cppreference.com/w/cpp/types/offsetof

	//color the object 
	Factory::createVertAttrib(1, 1, 4, sizeof(Vertex), (void*)(3 * sizeof(float)));

	//place the material on the object 
	Factory::createVertAttrib(1, 2, 2, sizeof(Vertex), (void*)(7 * sizeof(float)));

	//now that we have our buffer attributes settled, we can finally draw our square
	 glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

	glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(0); //we now disable our ability to draw, so we don't draw anything else unecessary.
}

