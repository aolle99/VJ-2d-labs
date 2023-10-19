#version 330

in vec2 position;
uniform vec2 scl;

void main()
{
	gl_Position = vec4(position*scl, 0.0, 1.0);
}
