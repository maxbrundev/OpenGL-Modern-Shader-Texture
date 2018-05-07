#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

namespace graphic
{
	class Shader
	{
	private:

	public:
		Shader() = default;
		~Shader() = default;

		static std::string GetShaderProgramSource(const std::string& p_filepath);

		static GLuint CompileShader(const GLuint& p_type, const std::string& p_source);

		static void CheckShaderError(GLuint& p_idProgram, const GLuint& p_type = 0);

		static GLuint LinkProgramme(const GLuint& p_vertexShaderProgram, const GLuint& p_fragmentShaderProgram);
	};
}
