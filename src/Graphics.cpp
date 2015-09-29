#include "Graphics.h"
#include "Vertices.h"
#include "Common.h"

//Function to initialise OpenGL
void initOpenGL()
{
	//Smoothshading
	glShadeModel(GL_SMOOTH);
	//clearthebackgroundtoblack
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Clearthedepthbufferto1.0
	glClearDepth(1.0f);
	//Enabledepthtesting
	glEnable(GL_DEPTH_TEST);
	//Thedepthtesttouse
	glDepthFunc(GL_LEQUAL);
	//Turnonbestperspectivecorrection
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//Function to set/reset viewport
void setViewport( int width, int height )
{
    //screen ration
    GLfloat ratio;

    //make sure height is always above 1
    if ( height == 0 ) {
        height = 1;
    }

    //calculate screen ration
    ratio = ( GLfloat )width / ( GLfloat )height;

    //Setup viewport
    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    //Change to poject matrix mode
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    //Calculate perspective matrix, using glu library functions
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    //Swith to ModelView
    glMatrixMode( GL_MODELVIEW );

    //Reset using the Indentity Matrix
    glLoadIdentity( );
}

