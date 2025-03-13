#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-1
//Making a Triangle/Square 
//With uniform color

namespace learn_basic {
	class chapter1 : public chapter
	{
		float vertices[8] = { -0.5f ,-0.5f,          //A
							0.5f , -0.5f,           //B
							0.5f , 0.5f ,           //C
							-0.5f , 0.5f };          //D


		unsigned int indices[6] = { 0, 1, 2,  // first Triangle
									2, 3, 0 };  // second Triangle
	public:
		Shader shader;
		VertexArray vao;
		VertexBuffer vbo;
		IndexBuffer ebo;
		VertexBufferLayout layout;
		//------------------------------------------------------------------

		void init_chapter()
		{
			shader.Gen("res/shaders/basic.shader");
			shader.SetUniform4f("u_Color", 1.0f, 0.0f, 1.0f, 1.0f);
			vao.Gen();
			vbo.Gen(vertices, sizeof(vertices));
			ebo.Gen(indices, sizeof(indices));
			layout.Push<float>(2);
			vao.AddBuffer(vbo, layout);

			vao.UnBind();
			vbo.UnBind();
			ebo.UnBind();
			shader.UnBind();
		}

		void draw_chapter()
		{
			shader.Bind();
			vao.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
			vao.UnBind();
			shader.UnBind();
		}

		void key_input_chapter(GLFWwindow* window)
		{

		}

		void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos)
		{

		}
	};
}

