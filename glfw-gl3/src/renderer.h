#pragma once

#include <GL/glew.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) gLClearError();\
	x;\
	ASSERT(gLLogCall(#x, __FILE__, __LINE__))

void gLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool glLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "): " << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}