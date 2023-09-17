#include <GL/glew.h>
#include <GL/gl.h>
#include "Circle.h"
#include <math.h>
#include <iostream>


Circle *Circle::createCircle(float x, float y, float radius, int triangles, ShaderProgram &program)
{
	Circle *circle = new Circle(x, y, radius, triangles, program);

	return circle;
}


Circle::Circle(float x, float y, float radius, int triangles, ShaderProgram &program)
{
	float circumference = 2 * 3.14159;
	n_vertices = triangles * 3;
	float* vertices = new float[n_vertices*2];
	float m_ang_increment = circumference / triangles;

	int i = 0;

	for (float m_ang = 0; m_ang < circumference; m_ang +=m_ang_increment) {
		vertices[i++] = x;
		vertices[i++] = y;
		vertices[i++] = x + radius * sin(m_ang);
		vertices[i++] = y + radius * cos(m_ang);
		vertices[i++] = x + radius * sin(m_ang + m_ang_increment);
		vertices[i++] = y + radius * cos(m_ang + m_ang_increment);
	}




	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, n_vertices * 2 * sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2);
	//IMPORTANTE
	delete[] vertices;
}

void Circle::render() const
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glDrawArrays(GL_TRIANGLES, 0, n_vertices);
}

void Circle::free()
{
	glDeleteBuffers(1, &vbo);
}

