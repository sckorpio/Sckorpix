#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-1
//Making a Triangle/Square 
//With uniform color

namespace learn_texture {
	class chapter1 : public chapter
	{
		float vertices[16] = { -0.5f ,-0.5f, 0.0f ,0.0f,           //A
							  0.5f ,-0.5f, 1.0f ,0.0f,           //B
							  0.5f , 0.5f, 1.0f ,1.0f,           //C
							 -0.5f , 0.5f, 0.0f ,1.0f };          //D


		unsigned int indices[6] = { 0, 1, 2,  // first Triangle
								    2, 3, 0 };  // second Triangle

		 Shader shader;
		 VertexArray vao;
		 VertexBuffer vbo;
		 IndexBuffer ebo;
		 VertexBufferLayout layout;
		 Texture texture;
	
		//------------------------------------------------------------------

		void init_chapter()
		{
			shader.Gen("res/shaders/texture_2D_shader.shader");
			shader.Bind();

			texture.Gen("res/textures/nice.jpg");
			texture.Bind();
			shader.SetUniform1i("u_Texture", 0);

			vao.Gen();
			vbo.Gen(vertices, sizeof(vertices));
			ebo.Gen(indices, sizeof(indices));
			layout.Push<float>(2);
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
			texture.Bind();
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

