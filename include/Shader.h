#ifndef _Shader_h
#define _Shader_h

#include "Common.h"

enum SHADER_TYPE
{
	VERTEX_SHADER=GL_VERTEX_SHADER,
	FRAGMENT_SHADER=GL_FRAGMENT_SHADER
};

GLuint LoadShaderFromMemory(const char * pMem, SHADER_TYPE shaderType);

GLuint LoadShaderFromFile(const std::string& filename, SHADER_TYPE shaderType);

bool checkForCompilerErrors(GLuint shaderProgram);

#endif