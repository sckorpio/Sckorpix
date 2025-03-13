#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-1
//learning blend mode

namespace learn_blend_modes {
	class chapter1 : public chapter
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
		Texture textureBG;
		Texture textureFG;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;

		int blend_mode = 1;
		bool upPressed;
		bool downPressed;

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

			shader.Gen("res/shaders/blend_modes/blend_mode1_shader.shader");
			shader.Bind();

			shader.SetUniformMat4f("u_projection", proj);
			shader.SetUniformMat4f("u_viewport", view);
			shader.SetUniformMat4f("u_model", model);

			textureBG.Gen("res/textures/FaceMaskBackground.jpg");
			textureBG.Bind(0);
			shader.SetUniform1i("u_BG_Texture", 0);

			textureFG.Gen("res/textures/FaceMaskForeground.png");
			textureFG.Bind(7);
			shader.SetUniform1i("u_FG_Texture", 7);

			shader.SetUniform1i("u_Mode", blend_mode);

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
			shader.SetUniform1i("u_Mode", blend_mode);
			textureBG.Bind(0);
			//textureFG.Bind(1);
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
			bool upCurrentlyPressed = glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS;
			bool downCurrentlyPressed = glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS;

			if (!upPressed && upCurrentlyPressed) 
			{ 
				blend_mode++;
			}

			if (!downPressed && downCurrentlyPressed)
			{
				blend_mode--;
			}
			upPressed = upCurrentlyPressed;
			downPressed = downCurrentlyPressed;
		}

		void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos)
		{

		}
		//----------------------------------------------

		void Transformation1()
		{
			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::scale(trans, glm::vec3(0.741,1,1));
			trans = glm::scale(trans, glm::vec3(2, 2, 1));
			model = trans;
			shader.SetUniformMat4f("u_model", model);
		}

	};
}

