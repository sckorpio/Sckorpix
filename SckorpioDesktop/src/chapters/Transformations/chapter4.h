#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-2
//Making a cube in 3D
//using MVP matrix
//learning Orthogonal/Perspective in 3D
//Making a cube with Texture
//Apply transformations on it , now using mvp matrix
//Apply translate,rotate,scale (model )
// use ortho/perspective for proj
// shiting viewport matrix for 3D

namespace learn_transformation {

	class chapter4 : public chapter
	{

	float vertices[6*2*3*5] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};


		 Shader shader;
		 VertexArray vao;
		 VertexBuffer vbo;
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
			layout.Push<float>(3);
			layout.Push<float>(2);
			vao.AddBuffer(vbo, layout);

			vao.UnBind();
			vbo.UnBind();
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
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(vertices[0])));
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

			//for model
			glm::mat4 trans = glm::mat4(1.0f);

			trans = glm::rotate(trans, t, glm::vec3(1.0f, 1.0f, 1.0f));

			model = trans;
			//----------------------------------------------------------------------
			shader.SetUniformMat4f("u_model", model);
		}

		void Transformation2()
		{
			float t = (float)glfwGetTime() / 2.0f;
			int ti = (int)(t);
			float min_s = 0.2f;
			float pt;
			float kt = 0.0f;

			pt = t - (int)(t);
			kt = (1.0f - min_s) * pt + min_s;

			if (ti % 2 == 0)
				kt = 1.0f - kt + min_s;

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::scale(trans, glm::vec3(kt, kt, kt));
			trans = glm::rotate(trans, t, glm::vec3(1.0f, 1.0f, 1.0f));

			model = trans;
			shader.SetUniformMat4f("u_model", model);
		}



	};
}

