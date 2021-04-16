#include <windows.h>
#include "gl/gl.h"
#include "GLFW/glfw3.h"
#include <cmath>

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

void AAQuad(float topX, float topY, float sizeX, float sizeY)
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(topX, topY, 0);
	glVertex3f(topX + sizeX, topY, 0);
	glVertex3f(topX, topY - sizeY, 0);
	glVertex3f(topX + sizeX, topY - sizeY, 0);
	glEnd();
}

void render_loop()
{
	for(char i = 0; i < 54; i++)
	{
		AAQuad(-0.9 + ((i % 18) * 0.1), 0.5 - (floor(i / 18) * 0.1), 0.08, 0.07);
	}
}

void main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

	glfwMakeContextCurrent(window);

	glViewport(0, 0, 640, 480);

	// line drawing stuff
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0.0, 640.0, 0.0, 480.0, 0.0, 1.0);

	while (!glfwWindowShouldClose(window))
	{
		// input 
		processInput(window);

		// rendering
		render_loop();

		// confusing bits
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
}
