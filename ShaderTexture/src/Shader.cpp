#include "Shader.h"

using namespace graphic;

std::string Shader::GetShaderProgramSource(const std::string& p_filepath)
{
	std::ifstream file;
	std::stringstream dataStream;
	std::string code;

	try
	{
		file.open(p_filepath);
		dataStream << file.rdbuf();
		code = dataStream.str();
		file.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Error while opening file : " << p_filepath << "\n";
		std::cout << e.what() << "\n";
	}
	return code;
}

GLuint graphic::Shader::CompileShader(const GLuint & p_type, const std::string & p_source)
{
	GLuint id = glCreateShader(p_type);
	const GLchar* src = p_source.c_str();

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	CheckShaderError(id, p_type);

	return id;
}

void Shader::CheckShaderError(GLuint& p_idProgram, const GLuint& p_type)
{
	int result;
	int length = 0;
	char* message = nullptr;

	glGetShaderiv(p_idProgram, (p_type != 0) ? GL_COMPILE_STATUS : GL_LINK_STATUS, &result);

	if (result == GL_FALSE)
	{
		glGetShaderiv(p_idProgram, GL_INFO_LOG_LENGTH, &length);

		message = static_cast<char*>(alloca(length * sizeof(char)));
		glGetShaderInfoLog(p_idProgram, length, &length, message);

		if (p_type == 0)
		{
			std::cout << "Failed shader compilation\n";
		}
		else
		{
			std::cout << "Failed " << (p_type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " shader compilation!\n";
		}

		std::cout << message << "\n";

		(p_type != 0) ? glDeleteShader(p_idProgram) : glDeleteProgram(p_idProgram);

		p_idProgram = 0;
	}
}

GLuint Shader::LinkProgramme(const GLuint& p_vertexShaderProgram, const GLuint& p_fragmentShaderProgram)
{
	GLuint id = glCreateProgram();

	glAttachShader(id, p_vertexShaderProgram);
	glAttachShader(id, p_fragmentShaderProgram);
	glLinkProgram(id);

	CheckShaderError(id);

	if (id != 0)
	{
		glDeleteShader(p_vertexShaderProgram);
		glDeleteShader(p_fragmentShaderProgram);
	}

	return id;
}