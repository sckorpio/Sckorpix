#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;
layout(location = 1) in vec3 Col;
layout(location = 2) in vec2 TexCoord;
out vec3 v_Col;
out vec2 v_TexCoord;

uniform mat4 u_model;
uniform mat4 u_viewport;
uniform mat4 u_projection;


void main()
{
	mat4 mvp = u_projection * u_viewport * u_model;
	gl_Position = mvp * vec4(Pos.x, Pos.y, Pos.z, 1.0);
	v_Col = Col;
	v_TexCoord = TexCoord;
}

#shader fragment
#version 330 core
out vec4 FragColor;
in vec3 v_Col;
in vec2 v_TexCoord;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord) * vec4(v_Col, 1.0f);
	FragColor = texColor;

}
