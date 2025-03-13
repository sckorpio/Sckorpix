#ifndef CHAPTER_H
#define CHAPTER_H

#include <GL/glew.h>  
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <signal.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "vertexbufferlayout.h"
#include "shader.h"
#include "texture.h"
#include "debug.h"
#include "Camera.h"

#define width 600
#define height 600

class chapter
{
public:
	virtual void init_chapter() = 0;
	virtual void draw_chapter() = 0;
	virtual void key_input_chapter(GLFWwindow* window) = 0;
	virtual void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos) = 0;

};

#endif // CHAPTER_H