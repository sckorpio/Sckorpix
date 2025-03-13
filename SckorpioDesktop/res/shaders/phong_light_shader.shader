#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;
layout(location = 0) in vec3 Norm;

out vec3 Normal;
out vec3 FragPos;
uniform mat4 u_model;
uniform mat4 u_viewport;
uniform mat4 u_projection;

void main()
{
	Normal = Norm;
	FragPos = vec3(u_model * vec4(Pos, 1.0));
	mat4 mvp = u_projection * u_viewport * u_model;
	gl_Position = mvp * vec4(Pos.x, Pos.y, Pos.z, 1.0);
}

#shader fragment
#version 330 core
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;
uniform vec3 u_objectColor;
uniform vec3 u_lightColor;
uniform vec3 u_lightPosition;
uniform float u_ambientStrength;

void main()
{
	vec3 normDir = normalize(Normal);
	vec3 lightDir = normalize(u_lightPosition - FragPos);
	float diffuseImpact = max(dot(normDir, lightDir), 0.0f);
	vec3 diffuseLightColor = diffuseImpact * u_lightColor;
	vec3 ambientLightColor = u_ambientStrength * u_lightColor;
	vec3 phongLightColor = diffuseLightColor + ambientLightColor;
	FragColor = vec4(u_objectColor * phongLightColor, 1.0f);
}
