#include <windows.h>
#include "gl/gl.h"

#include "GLFW/glfw3.h"

void main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);


	while(1)
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
