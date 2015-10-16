#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Common.h"

GLuint laodTextureFromFile(const string& filename);
GLuint convertSDLSurfaceToTexture(SDL_Surface*surface);

#endif