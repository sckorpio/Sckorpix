#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-1
//Making a Square with Texture
//Apply transformations on it
//Apply translate,rotate,scale
//apply some animations using time etc

namespace learn_transformation {
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
			shader.Gen("res/shaders/texture_2D_transformation_shader.shader");
			shader.Bind();

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
			Transformation4();
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
			glm::mat4 trans = glm::mat4(1.0f);

			trans = glm::rotate(trans, glm::radians(60.0f), glm::vec3(0.0, 0.0, 1.0));
			trans = glm::translate(trans, glm::vec3(0.5f, 0.0f, 0.0f));
			trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
			shader.SetUniformMat4f("u_Transform", trans);
		}

		void Transformation2()
		{
			glm::mat4 trans = glm::mat4(1.0f);

			trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
			trans = glm::rotate(trans, glm::radians(60.0f), glm::vec3(0.0, 0.0, 1.0));
			trans = glm::translate(trans, glm::vec3(0.5f, 0.0f, 0.0f));

			shader.SetUniformMat4f("u_Transform", trans);
		}

		void Transformation3()
		{
			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
			trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
			trans = glm::translate(trans, glm::vec3(1.5f, 0.0f, 0.0f));

			shader.SetUniformMat4f("u_Transform", trans);
		}

		void Transformation4()
		{
			float t = (float)glfwGetTime();
			int ti = (int)(t);
			float pt;

			pt = t - (int)(t);

			if (ti % 2 == 0)
				pt = 1.0f - pt;

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
			trans = glm::rotate(trans, t, glm::vec3(0.0, 0.0, 1.0));
			trans = glm::translate(trans, glm::vec3(1.5f, 0.0f, 0.0f));
			trans = glm::scale(trans, glm::vec3(pt, pt, pt));

			shader.SetUniformMat4f("u_Transform", trans);
		}
	};
}

