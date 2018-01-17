#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
	};

	std::cout << "GL_VERSION: " << glGetString(GL_VERSION);
	float positions[6] = {
		-0.5f, -0.5f,
		0.0f,  0.5f,
		0.5f, -0.5f
	}; // This is vertexes of our triangle

	unsigned int buffer;
	glGenBuffers(1, &buffer);				// Generate/Create a GL Buffer, we should provide an Integer as a memory which we can write into 
	glBindBuffer(GL_ARRAY_BUFFER, buffer);	// How do I want to use the GL Buffer? Define it to a specific buffer:
											//	target - GL_ARRAY_BUFFER: it's just an array
											//	buffer - an integer comes from memory
											// if we use glBindBuffer(GL_ARRAY_BUFFER, 0); then GPU won't draw the triangle out since we bind something else

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);	
	// above: Set data which we want to use to the specific GPU buffer
	// : STATIC, DYNAMIC: we should let GPU knows that if the buffer can be modified more than ONCE.
	// : DRAW: we want to draw things with the buffer, so use it


	/*
	* Loop until the user closes the window:
	* : This is like onDraw, so it will draw on each frame when updating,
	* : but we don't have to put the buffer code here, but draw command only
	*/
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// TODO: modern gl codes begin:
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// above: glDrawArrays ¡X render primitives from array data
		// : first - 0 means the index of the array we want to start
		// : count - the number of axis (x, y) of the array we want to draw
		// NOTE: similar API - glDrawElements(GL_TRIANGLES, 3, UNSIGNED_INT, ...) used with index buffer
		


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}