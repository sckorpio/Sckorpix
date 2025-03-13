#shader vertex
#version 330 core
layout(location = 0) in vec3 Pos;
layout(location = 1) in vec2 TexCoord;
out vec2 v_TexCoord;

uniform mat4 u_model;
uniform mat4 u_viewport;
uniform mat4 u_projection;


void main()
{
	mat4 mvp = u_projection * u_viewport * u_model;
	gl_Position = mvp * vec4(Pos.x, Pos.y, Pos.z, 1.0);
	v_TexCoord = TexCoord;
}

#shader fragment
#version 330 core
out vec4 FragColor;
in vec2 v_TexCoord;
uniform sampler2D u_FG_Texture;
uniform sampler2D u_BG_Texture;
uniform int u_Mode;

//ADD--------------------------------------------------
vec3 blend_Add(vec3 bg, vec3 fg)
{
	return min(bg + fg, vec3(1.0));
}
//AVERAGE----------------------------------------------
vec3 blend_Average(vec3 bg, vec3 fg)
{
	return (bg + fg)/2;
}
//COLOR_BURN-------------------------------------------
float blend_ColorBurn(float bg, float fg) 
{
	return (fg == 0.0) ? fg : max((1.0 - ((1.0 - bg) / fg)), 0.0);
}

vec3 blend_ColorBurn(vec3 bg, vec3 fg) 
{
	return vec3(blend_ColorBurn(bg.r, fg.r), blend_ColorBurn(bg.g, fg.g), blend_ColorBurn(bg.b, fg.b));
}
//COLOR_DODGE-------------------------------------------
float blend_ColorDodge(float bg, float fg)
{
	return (fg == 1.0) ? fg : min(bg / (1.0 - fg), 1.0);
}

vec3 blend_ColorDodge(vec3 bg, vec3 fg)
{
	return vec3(blend_ColorDodge(bg.r, fg.r), blend_ColorDodge(bg.g, fg.g), blend_ColorDodge(bg.b, fg.b));
}

//DARKEN---------------------------------------------
float blend_Darken(float bg, float fg)
{
	return min(fg, bg);
}

vec3 blend_Darken(vec3 bg, vec3 fg)
{
	return vec3(blend_Darken(bg.r, fg.r), blend_Darken(bg.g, fg.g), blend_Darken(bg.b, fg.b));
}

//DIFFERENCE---------------------------------------------
vec3 blend_Difference(vec3 bg, vec3 fg)
{
	return abs(bg - fg);
}

//EXCLUSION---------------------------------------------
vec3 blend_Exclusion(vec3 bg, vec3 fg)
{
	return bg + fg - 2.0 * bg * fg;
}

//REFLECT-----------------------------------------------
float blend_Reflect(float bg, float fg)
{
	return (fg == 1.0) ? fg : min(bg * bg / (1.0 - fg), 1.0);
}

vec3 blend_Reflect(vec3 bg, vec3 fg)
{
	return vec3(blend_Reflect(bg.r, fg.r), blend_Reflect(bg.g, fg.g), blend_Reflect(bg.b, fg.b));
}
//OVERLAY-------------------------------------------------
float blend_Overlay(float bg, float fg)
{
	return bg < 0.5 ? (2.0 * bg * fg) : (1.0 - 2.0 * (1.0 - bg) * (1.0 - fg));
}

vec3 blend_Overlay(vec3 bg, vec3 fg)
{
	return vec3(blend_Overlay(bg.r, fg.r), blend_Overlay(bg.g, fg.g), blend_Overlay(bg.b, fg.b));
}

//GLOW--------------------------------------------------------
vec3 blend_Glow(vec3 bg, vec3 fg)
{
	return blend_Reflect(fg, bg);
}



void main()
{
	vec4 BG = texture(u_BG_Texture, v_TexCoord);
	vec4 FG = texture(u_FG_Texture, v_TexCoord);
	vec3 BGcolor = BG.rgb;
	vec3 FGcolor = FG.rgb;
	vec3 result;
	
	if (u_Mode == 0)
		result = FGcolor;

	else if (u_Mode == 1)
		result = blend_Add(BGcolor, FGcolor);

	else if (u_Mode == 2)
		result = blend_Average(BGcolor, FGcolor);

	else if (u_Mode == 3)
		result = blend_ColorBurn(BGcolor, FGcolor);

	else if (u_Mode == 4)
		result = blend_ColorDodge(BGcolor, FGcolor);

	else if (u_Mode == 5)
		result = blend_Darken(BGcolor, FGcolor);

	else if (u_Mode == 6)
		result = blend_Difference(BGcolor, FGcolor);

	else if (u_Mode == 7)
		result = blend_Exclusion(BGcolor, FGcolor);

	else if (u_Mode == 8)
		result = blend_Reflect(BGcolor, FGcolor);

	else if (u_Mode == 9)
		result = blend_Overlay(BGcolor, FGcolor);

	else if (u_Mode == 10)
		result = blend_Glow(BGcolor, FGcolor);


	FragColor = vec4(result, min(FG.a, BG.r) );
}
