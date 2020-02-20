#pragma once

#include <iostream>
#include"Shaders.h"
#include "SimpleCamera.h"
#include "Vertex.h"

#include "InitLibs.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

namespace Nept
{
	class basicRender
	{
		public:
			basicRender();
			~basicRender();
			void InitWindow(SDL_Window** window);
			void MainLoop();
			static void VertexSetup(GLuint VertexArrayID);
			void RenderTriangle(GLuint triangleVerBuff);
			void SetColors();
			void FullScreen();
			bool running = true;
			bool fullscreen;

		private:
			SDL_Window* window = nullptr;
			SDL_Event ev;
			GLuint VertexArrayID = 0; //we name Our VAO
			GLuint triangleVerBuff = 0;//then we pass our triangle to be worked by open gl, we do this by creating a buffer accordingly
			GLuint elementBuffer;
			GLint basicProgramID;

	};

}

