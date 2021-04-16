#include <windows.h>
#include "gl/gl.h"
#include "GLFW/glfw3.h"

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	}
}

void main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

	glViewport(0, 0, 640, 480);

	while (!glfwWindowShouldClose(window))
	{
		// input 
		processInput(window);

		// rendering


		// confusing bits
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
}
