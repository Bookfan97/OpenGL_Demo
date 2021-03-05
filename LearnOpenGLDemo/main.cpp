#include "main.h"

#include <iostream>

#include "glad.h"
#include "glfw3.h"
//#include "gl3w.h"
#include "gl/GL.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//const char* glsl_version;

int main()
{
	//Instantiate window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	//Create window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "FAILED TO CREATE GLFW WINDOW" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//Initialize GLAD pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;
		return -1;
	}

	 //// Setup Dear ImGui context
  //  IMGUI_CHECKVERSION();
  //  ImGui::CreateContext();
  //  ImGuiIO &io = ImGui::GetIO();
  //  // Setup Platform/Renderer bindings
  //  ImGui_ImplGlfw_InitForOpenGL(window, true);
  //  ImGui_ImplOpenGL3_Init(glsl_version);
  //  // Setup Dear ImGui style
  //  ImGui::StyleColorsDark();
	
	//Create viewport
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Render loop
	while (!glfwWindowShouldClose(window))
	{
		//Input
		processInput(window);

		//Render commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Check and call events, swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
