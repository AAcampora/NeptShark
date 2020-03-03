#pragma once

#include <iostream>
#include "InitLibs.h"
#include"Shaders.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

#include "SimpleCamera.h"
#include "Vertex.h"
#include "Texture.h"
#include "Factory.h"

namespace Nept
{

	

	class basicRender
	{
		public:
			basicRender();
			~basicRender();
			void InitWindow(SDL_Window** window);
			void MainLoop();
			void RenderObject(GLuint triangleVerBuff);
			void SetColors();
			static void VertexSetup(GLuint VertexArrayID);
			bool running = true;


		private:
			SDL_Window* window = nullptr;
			SDL_Event ev;
			GLuint VertexArrayID = 0; //we name Our VAO
			GLuint triangleVerBuff = 0;//then we pass our triangle to be worked by open gl, we do this by creating a buffer accordingly
			GLuint elementBuffer =0;
			GLuint* elementBufferPtr;
			GLint basicProgramID;
			GLuint baseTextureLocation;
			GLuint baseTextureID;

	};



};

