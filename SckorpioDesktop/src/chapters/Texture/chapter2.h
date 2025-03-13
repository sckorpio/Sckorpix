#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-2
////Making a Square with Texture and vertices color


namespace learn_texture {
	class chapter2 : public chapter
	{
		float vertices[32] = { -0.5f ,-0.5f, 0.0f,         //A
							  1.0f , 0.0f, 0.0f,		 //red
							  0.0f ,0.0f,
							  0.5f , -0.5f, 0.0f,        //B
							  0.0f , 1.0f, 0.0f,		 //green
							  1.0f ,0.0f,
							  0.5f , 0.5f , 0.0f,		 //C
							  0.0f , 0.0f, 1.0f,		 //blue
							  1.0f ,1.0f,
							 -0.5f , 0.5f, 0.0f,         //D
							  1.0f , 1.0f, 0.0f,         //yellow
							  0.0f ,1.0f };


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
			shader.Gen("res/shaders/texture_2D_color_vertex_shader.shader");
			shader.Bind();

			texture.Gen("res/textures/wood4.png");
			texture.Bind();
			shader.SetUniform1i("u_Texture", 0);

			vao.Gen();
			vbo.Gen(vertices, sizeof(vertices));
			ebo.Gen(indices, sizeof(indices));
			layout.Push<float>(3);
			layout.Push<float>(3);
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

