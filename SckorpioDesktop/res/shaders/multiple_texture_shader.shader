#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;
layout(location = 1) in vec3 Col;
layout(location = 2) in vec2 TexCoord;
layout(location = 3) in float TexIndex;
out vec3 v_Col;
out vec2 v_TexCoord;
out float v_TexIndex;

uniform mat4 u_model;
uniform mat4 u_viewport;
uniform mat4 u_projection;


void main()
{
	mat4 mvp = u_projection * u_viewport * u_model;
	gl_Position = mvp * vec4(Pos.x, Pos.y, Pos.z, 1.0);
	v_Col = Col;
	v_TexCoord = TexCoord;
	v_TexIndex = TexIndex;
}

#shader fragment
#version 330 core
out vec4 FragColor;
in vec3 v_Col;
in vec2 v_TexCoord;
in float v_TexIndex;
uniform sampler2D u_Texture[2];

void main()
{
	int tex_index = int(v_TexIndex);
	vec4 texColor = texture(u_Texture[tex_index], v_TexCoord) * vec4(v_Col, 1.0f);
	FragColor = texColor;
}
