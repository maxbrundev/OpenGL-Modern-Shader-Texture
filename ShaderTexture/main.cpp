#include "Triangle.h"
#include "Shader.h"

#include <GLFW/glfw3.h>
#include <SOIL.h>

int main(int argc, char* argv[])
{
	shape::Triangle triangle;
	graphic::Shader shader;
	
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Texture", nullptr, nullptr);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString);
	}
	std::cout << glewGetString(GLEW_VERSION);
	std::cout << glGetString(GL_VERSION);

	triangle.InitShape();

	GLuint texture = SOIL_load_OGL_texture("res/texture.jpg",SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
	if (texture == 0)
	{
		std::cerr << SOIL_last_result();
	}
	glBindTexture(GL_TEXTURE_2D, texture);

	GLuint vertexShaderProgram = shader.CompileShader(GL_VERTEX_SHADER, shader.GetShaderProgramSource("res/color.vert"));
	GLuint fragmentShaderProgram = shader.CompileShader(GL_FRAGMENT_SHADER, shader.GetShaderProgramSource("res/color.frag"));
	GLuint programShader = shader.LinkProgramme(vertexShaderProgram, fragmentShaderProgram);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.7f, 0.4f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(programShader);

		triangle.DrawShape();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwTerminate();

	return 0;
}