#pragma once
#include <SDL.h> 
#include <glew.h> // load the openGl exentsion Wrangler
#include <SDL_opengl.h>//load open Gl

#include <string>
#include <vector>
#include <fstream>

//using a struct cos this file doesn't feel needs to be expanded or needs the same data menagement as a Class
struct InitLibs
{
	int SDLInit();
	
	static void GlewInit(SDL_Window **window);
};

