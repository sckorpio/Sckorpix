#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-2
//Batch rendering with color, texture, 
//Note: the texture wil remain same in all geometry rendered


namespace learn_batch_rendering 
{
	class chapter2 : public chapter
	{
		float vertices[2*32] =    { 0.0f	, 0.0f, 0.0f,       //A
									1.0f	, 0.0f, 0.0f,		 //red
									0.0f	, 0.0f,
									100.0f, 0.0f, 0.0f ,      //B
									0.0f	, 1.0f, 0.0f,		 //green
									1.0f  , 0.0f,
									100.0f ,100.0f, 0.0f ,     //C
									0.0f , 0.0f, 1.0f,		 //blue
									1.0f ,1.0f,
									0.0f   ,100.0f, 0.0f ,           //D
									1.0f , 1.0f, 0.0f,         //yellow
									0.0f ,1.0f,

									200.0f , 200.0f, 0.0f,       //A
									1.0f	 , 0.0f, 0.0f,		 //red
									0.0f	 , 0.0f,
									300.0f , 200.0f, 0.0f ,      //B
									0.0f , 1.0f, 0.0f,		 //green
									1.0f ,0.0f,
									300.0f ,300.0f, 0.0f ,     //C
									0.0f , 0.0f, 1.0f,		 //blue
									1.0f ,1.0f,
									200.0f   ,300.0f, 0.0f ,    //D
									1.0f , 1.0f, 0.0f,         //yellow
									0.0f ,1.0f };


		unsigned int indices[12] = { 0, 1, 2,  // first Triangle
									2, 3, 0,  // second Triangle

									4, 5, 6,  // first Triangle
									6, 7, 4 };  // second Triangle

		Shader shader;
		VertexArray vao;
		VertexBuffer vbo;
		IndexBuffer ebo;
		VertexBufferLayout layout;
		Texture texture;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;

		//------------------------------------------------------------------

		void init_chapter()
		{
			model = glm::mat4(1.0f);
			view = glm::mat4(1.0f);
			proj = glm::mat4(1.0f);

			//for projection
			glm::mat4 ortho = glm::ortho(0.0f, (float)(width), 0.0f, (float)(height), -1.0f, 1.0f);
			proj = ortho;

			//for viewport


			shader.Gen("res/shaders/pos_col_tex_mvp_shader.shader");
			shader.Bind();

			shader.SetUniformMat4f("u_projection", proj);
			shader.SetUniformMat4f("u_viewport", view);
			shader.SetUniformMat4f("u_model", model);

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
			glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);
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

