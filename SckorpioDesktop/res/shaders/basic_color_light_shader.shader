#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;

uniform mat4 u_model;
uniform mat4 u_viewport;
uniform mat4 u_projection;

void main()
{
	mat4 mvp = u_projection * u_viewport * u_model;
	gl_Position = mvp * vec4(Pos.x, Pos.y, Pos.z, 1.0);
}

#shader fragment
#version 330 core
out vec4 FragColor;
uniform vec3 u_objectColor;
uniform vec3 u_lightColor;

void main()
{
	FragColor = vec4(u_objectColor * u_lightColor, 1.0f);
}
