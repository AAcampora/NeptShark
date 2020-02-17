#pragma once
#include <SDL.h> //load the sdl Library
#include <glew.h> // load the openGl exentsion Wrangler
#include <SDL_opengl.h>//load open Gl
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

//include all the sTD data
#include <string>
#include <vector>
#include <fstream>

using namespace glm;
class SimpleCamera 
{

public:

	SimpleCamera(GLint basicProgramID);
	SimpleCamera() = default;

	void GenCameraUniforms();

	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;
	vec3 position;
	mat4 translation;
	vec3 cameraPosition;
	vec3 cameraTarget;
	vec3 cameraUP;
	mat4 view;
	mat4 projection;



};