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
	class chapter3 : public chapter
	{
		 float vertices[20] = {
			// positions          // texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
		};


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

			//proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);   //Try ortho in 3D but make view matirx I

			proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

			//for viewport

			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

			//--------

			shader.Gen("res/shaders/texture_mvp_shader.shader");
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
			Transformation2();
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
			float t = (float)glfwGetTime();
			int ti = (int)(t);
			float pt;

			pt = t - (int)(t);

			if (ti % 2 == 0)
				pt = 1.0f - pt;

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::rotate(trans, glm::radians(-70.0f), glm::vec3(1.0, 0.0, 0.0));
			trans = glm::scale(trans, glm::vec3(pt, pt, pt));
			model = trans;
			shader.SetUniformMat4f("u_model", model);
		}

		void Transformation2()
		{
			float t = (float)glfwGetTime();
			int ti = (int)(t);
			float pt;

			pt = t - (int)(t);

			if (ti % 2 == 0)
				pt = 1.0f - pt;

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::rotate(trans, glm::radians(-70.0f), glm::vec3(1.0, 0.0, 0.0));
			trans = glm::scale(trans, glm::vec3(pt, pt, pt));
			model = trans;
			shader.SetUniformMat4f("u_model", model);
		}



	};
}

