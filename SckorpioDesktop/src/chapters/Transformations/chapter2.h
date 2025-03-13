#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-2
//learning Orthogonal in 2D
//Making a Square with Texture
//Apply transformations on it , now using mvp matrix
//Apply translate,rotate,scale (model )
// use ortho for proj
// use Identity matrix for viewport
//using MVP matrix

namespace learn_transformation {
	class chapter2 : public chapter
	{
		 float vertices[16] = { 0.0f   ,0.0f,   0.0f ,0.0f,           //A
							100.0f ,0.0f,   1.0f ,0.0f,           //B
							100.0f ,100.0f, 1.0f ,1.0f,           //C
							0.5f   ,100.5f, 0.0f ,1.0f };         //D


		 unsigned int indices[6] = { 0, 1, 2,  // first Triangle
								     2, 3, 0 };  // second Triangle

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



			//--------

			shader.Gen("res/shaders/texture_mvp_shader.shader");
			shader.Bind();

			shader.SetUniformMat4f("u_projection", proj);
			shader.SetUniformMat4f("u_viewport", view);
			shader.SetUniformMat4f("u_model", model);

			texture.Gen("res/textures/unicorn.jpg");
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
			//----------------------------
			Transformation1();
			//---------------------------------------

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
		//----------------------------------------------

		void Transformation1()
		{
			//for model
			glm::mat4 trans = glm::mat4(1.0f);

			trans = glm::translate(trans, glm::vec3(300.0f, 400.0f, 0.0f));
			trans = glm::scale(trans, glm::vec3(0.8f, 0.8f, 0.8f));
			trans = glm::rotate(trans, glm::radians(60.0f), glm::vec3(0.0, 0.0, 1.0));

			model = trans;
			//----------------------------------------------------------------------
			shader.SetUniformMat4f("u_model", model);
		}

		
	};
}

