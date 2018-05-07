#pragma once

#include <iostream>

#include <GL/glew.h>

#include "IShape.h"

namespace shape
{
	class Triangle : Shape::IShape
	{
	private:
		const GLfloat m_vertices[15];

		GLuint m_vbo = {0};
		GLuint m_vao = {0};
		
	public:
		Triangle();
		~Triangle() = default;

		void InitShape() override;
		void DrawShape() override;
	};
}