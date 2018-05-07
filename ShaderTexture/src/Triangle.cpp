#include "Triangle.h"

using namespace shape;

Triangle::Triangle() : m_vertices { //POSITION				//TEXTURE
									-1.0f,	-1.0f,	0.0f,	0.0f, 0.0f,
									1.0f,	-1.0f,	0.0f,	2.0f, 0.0f,
									0.0f,	1.0f,	0.0f,	1.0f, 2.0f}
{
	std::cout << "Triangle Created" << std::endl;
}

void Triangle::InitShape()
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GLfloat), m_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), nullptr);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));
}

void Triangle::DrawShape()
{
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}