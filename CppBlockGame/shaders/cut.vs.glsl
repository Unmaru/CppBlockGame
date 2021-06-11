#version 150 core

uniform mat4 modelView;
uniform mat4 projection;

in vec3 pos;
in vec4 clr;

out vec4 v_clr;
out vec3 v_pos;

void main()
{
	v_clr = clr;
	v_pos = pos;
	gl_Position = projection * modelView * vec4(pos, 1.0);
}
