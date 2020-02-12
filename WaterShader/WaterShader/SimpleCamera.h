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


class SimpleCamera 
{

public:

	SimpleCamera(GLint basicProgramID);
	SimpleCamera() = default;

	void GenCameraUniforms();

	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;
	glm::vec3 position;
	glm::mat4 translation;
	glm::vec3 cameraPosition;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUP;
	glm::mat4 view;
	glm::mat4 projection;



};