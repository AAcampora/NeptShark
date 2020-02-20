
//* the entry point of my application *//
//the entrypoint will run my application through its steps
#include "main.h"  //include the main header
using namespace Nept;
	
int main(int argc, char** argsv) 
{				
	//we are going to use this to check if the libraries have been initialised
	InitLibs libsInit;
	//create pointer for my renderer
	basicRender* NeptBasic = new basicRender();

	if (libsInit.SDLInit() == 0)
	{
		//check if the application is running, if yes, begin the main loop
		while (NeptBasic->running)
		{
			NeptBasic->MainLoop();
		}
	}
	else
	{
		std::cout << "error in initialising libraries";
	}

	//garbage collect everything if the application is closed.
	NeptBasic->~basicRender();
						
	return 0;
}
