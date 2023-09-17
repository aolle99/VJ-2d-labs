#ifndef _CIRCLE_INCLUDE
#define _CIRCLE_INCLUDE


#include "ShaderProgram.h"

class Circle
{
private:
	Circle(float x, float y, float radius, int triangles, ShaderProgram &program);
public:
	static Circle *createCircle(float x, float y, float radius, int triangles, ShaderProgram &program);

	void render() const;
	void free();

private:
	GLuint vao;
	GLuint vbo;
	GLint posLocation;
	int n_vertices;
};
#endif // _QUAD_INCLUDE

