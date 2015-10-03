#include "Common.h"
#include "Graphics.h"

void render()
{
	//Set the clear colour(background)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//clear the colour and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Switch to Model View
	glMatrixMode(GL_MODELVIEW);
	//Reset using the Identity Matrix
	glLoadIdentity();
	//Translate to -5.0f on z-axis
	glTranslatef(0.0f, 0.0f, -5.0f);
	//Begin drawing triangles
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);//Colour of the vertices
		glVertex3f(0.0f, 1.0f, 0.0f);//Top
		glVertex3f(-1.0f, -1.0f, 0.0f);//Bottom Left
		glVertex3f(1.0f, -1.0f, 0.0f);//Bottom Right
	glEnd();
}

void update()
{

}


int main(int argc, char * arg[])
{
	bool run = true;
	//initeverything-SDL,ifitisnonzerowehaveaproblem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERRORSDL_Init" << SDL_GetError() << std::endl;
		return-1;
	}

	//Createawindow
	SDL_Window*window = SDL_CreateWindow("SDL",//windowtitle
		SDL_WINDOWPOS_CENTERED,//xposition,centered
		SDL_WINDOWPOS_CENTERED,//yposition,centered
		640, //width,inpixels
		480, //height,inpixels
		SDL_WINDOW_OPENGL //flags
		);
	//Create an OpenGL context associated with the window.
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	//Initialisation
	//CallourInitOpenGLFunction
	initOpenGL();
	//Set our viewport
	setViewport(640, 480);

	//ValuetoholdtheeventgeneratedbySDL
	SDL_Event event;
	//GameLoop
	while (run)
	{
		//Whilewestillhaveeventsinthequeue
		while (SDL_PollEvent(&event)){
			//Geteventtype
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE){
				//setourbooleanwhichcontrolsthelooptofalse
				run = false;
			}
		}
		//Update
		update();
		//Then Draw
		render();

		//Call swap so that our GL back buffer is displayed
		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;

	//cleanup,reverseorder!!!
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
