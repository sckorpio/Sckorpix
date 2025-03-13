#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-2
// learning about phong lightning
// Ambient only

namespace learn_lightning
{
	class chapter2 : public chapter
	{
		float vertices[6 * 2 * 3 * 3] = {
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

		glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec3 objectColor = glm::vec3(1.0f, 1.0f, 0.0f);

		float ambientStrength = 0.3f;

		glm::vec3 lightPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cubePosition = glm::vec3(2.0f, 5.0f, -15.0f);



		Shader shaderObject;
		Shader shaderLight;
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

			//---shader for light---
			shaderLight.Gen("res/shaders/basic_color_light_shader.shader");
			shaderLight.Bind();

			shaderLight.SetUniformMat4f("u_projection", proj);
			shaderLight.SetUniformMat4f("u_viewport", view);
			shaderLight.SetUniformMat4f("u_model", model);

			shaderLight.SetUniform3fv("u_lightColor", lightColor);
			shaderLight.UnBind();
			//--------

			shaderObject.Gen("res/shaders/ambient_light_shader.shader");
			shaderObject.Bind();

			shaderObject.SetUniformMat4f("u_projection", proj);
			shaderObject.SetUniformMat4f("u_viewport", view);
			shaderObject.SetUniformMat4f("u_model", model);

			shaderObject.SetUniform3fv("u_lightColor", lightColor);
			shaderObject.SetUniform1f("u_ambientStrength", ambientStrength);
			shaderObject.UnBind();
			//-----------
			vao.Gen();
			vbo.Gen(vertices, sizeof(vertices));
			layout.Push<float>(3);
			vao.AddBuffer(vbo, layout);

			vao.UnBind();
			vbo.UnBind();

		}

		void draw_chapter()
		{
			vao.Bind();
			//----------------------------
			view = camera.CameraTransformation();
			Transformation1();
			//---------------------------------------
			vao.UnBind();
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
			shaderLight.Bind();
			shaderLight.SetUniformMat4f("u_model", model);
			shaderLight.SetUniformMat4f("u_viewport", view);
			shaderLight.SetUniform3fv("u_objectColor", lightColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(vertices[0])));
			shaderLight.UnBind();
			//-----------------object-------------------------
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePosition);
			float angle = 20.0f;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			shaderObject.Bind();
			shaderObject.SetUniformMat4f("u_model", model);
			shaderObject.SetUniformMat4f("u_viewport", view);
			shaderObject.SetUniform3fv("u_objectColor", objectColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (sizeof(vertices[0])));
			shaderObject.UnBind();
		}

	};
}

