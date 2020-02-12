#pragma once

#include <SDL.h> //load the sdl Library
#include <glew.h> // load the openGl exentsion Wrangler
#include <SDL_opengl.h>//load open Gl
#include"Shaders.h"
#include "SimpleCamera.h"

#include "SDL_initialiser.h"

#include "Window_Spawner.h"

#include "Glew_Initialiser.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

//include all the sTD data
#include <string>
#include <vector>
#include <fstream>
class NeptShark
{
public:

	NeptShark(SDL_Window** window);
	static void VertexSetup(GLuint VertexArrayID);
	void SetColors();
	void RenderTriangle(GLuint triangleVerBuff);
private:


};