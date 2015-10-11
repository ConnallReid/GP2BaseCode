#include "Shader.h"

//Load it from a memory buffer
GLuint LoadShaderFromMemory(const char * pMem, SHADER_TYPE shaderType)
{
	GLuint program = glCreateShader(shaderType);
	glShaderSource(program, 1, &pMem, NULL);
	glCompileShader(program);
	return program;
}

GLuint LoadShaderFromFile(const std::string& filename, SHADER_TYPE shaderType)
{
	string fileContents;
	ifstream file;
	file.open(filename.c_str(), std::ios::in);
	if (!file)
	{
		cout << "File could not be loaded" << endl;
		return 0;
	}

	//Calculats file size
	if (file.good())
	{
		file.seekg(0, std::ios::end);
		unsigned long len = file.tellg();
		file.seekg(std::ios::beg);
		if (len == 0)
		{
			std::cout << "File has no contents" << std::endl;
			return 0;
		}

		fileContents.resize(len);
		file.read(&fileContents[0], len);
		file.close();
		GLuint program = LoadShaderFromMemory(fileContents.c_str(), shaderType);
		return program;
	}
	return 0;
}

bool checkForCompilerErrors(GLuint shaderProgram)
{
	GLint isCompiled = 0;
	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &maxLength);

		//The max length includes the NULL character
		string infoLog;
		infoLog.resize(maxLength);
		glGetShaderInfoLog(shaderProgram, maxLength, &maxLength, &infoLog[0]);

		cout << "Shader not compiled" << infoLog << endl;

		//We don't need toe shader anymore.
		glDeleteShader(shaderProgram);
		return true;
	}
	return false;
}