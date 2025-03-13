#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-1
// learning about basic lightning & coloring

namespace learn_lightning 
{
	class chapter1 : public chapter
	{
		float vertices[6*2*3*3] = {
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f, -0.5f,  0.5f,
			0.5f, -0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,

			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,

			0.5f,  0.5f,  0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,

			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f,  0.5f,
			0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f, -0.5f,

			-0.5f,  0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f,  0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f, -0.5f
		};

		glm::vec3 lightColor = glm::vec3(0.0f, 1.0f, 1.0f);
		glm::vec3 objectColor = glm::vec3(1.0f, 1.0f, 0.0f);

		glm::vec3 lightPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cubePosition = glm::vec3(2.0f, 5.0f, -15.0f);


		Shader shader;
		VertexArray vao;
		VertexBuffer vbo;
		VertexBufferLayout layout;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;

		Camera camera;

		//------------------------------------------------------------------

		void init_chapter()
		{
			model = glm::mat4(1.0f);
			view = glm::mat4(1.0f);
			proj = glm::mat4(1.0f);

			camera.InitCamera();

			//for projection

			proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

			//for viewport

			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));


			//--------

			shader.Gen("res/shaders/basic_color_light_shader.shader");
			shader.Bind();

			shader.SetUniformMat4f("u_projection", proj);
			shader.SetUniformMat4f("u_viewport", view);
			shader.SetUniformMat4f("u_model", model);

			shader.SetUniform3fv("u_lightColor", lightColor);

			vao.Gen();
			vbo.Gen(vertices, sizeof(vertices));
			layout.Push<float>(3);
			vao.AddBuffer(vbo, layout);

			vao.UnBind();
			vbo.UnBind();
			shader.UnBind();
		}

		void draw_chapter()
		{
			shader.Bind();
			vao.Bind();
			//----------------------------
			view = camera.CameraTransformation();
			shader.SetUniformMat4f("u_viewport", view);
			Transformation1();
			//---------------------------------------
			vao.UnBind();
			shader.UnBind();
		}

		void key_input_chapter(GLFWwindow* window)
		{
			camera.KeyInput(window);
		}

		void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos)
		{
			camera.MouseInput(window, xpos, ypos);
		}

		//-----------------------

		void Transformation1()
		{
			//---------------Lights--------------------------
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
			shader.SetUniformMat4f("u_model", model);
			shader.SetUniform3fv("u_objectColor", lightColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(vertices[0])));

			//-----------------object-------------------------
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePosition);
			float angle = 20.0f;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

			shader.SetUniformMat4f("u_model", model);
			shader.SetUniform3fv("u_objectColor", objectColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(vertices[0])));

		}

	};
}

