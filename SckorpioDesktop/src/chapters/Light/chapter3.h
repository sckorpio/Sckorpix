#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-3
// learning about phong lightning
// Ambient 
// Diffuse


namespace learn_lightning
{
	class chapter3 : public chapter
	{
		float verticesLight[6 * 2 * 3 * 3] = {
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

		float verticesObject[6 * 2 * 3 * 6] = {
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
		};

		glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec3 objectColor = glm::vec3(1.0f, 1.0f, 0.0f);

		float ambientStrength = 0.3f;

		glm::vec3 lightPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cubePosition = glm::vec3(2.0f, 0.0f, -2.0f);



		Shader shaderObject;
		Shader shaderLight;

		VertexArray vaoLight;
		VertexBuffer vboLight;
		VertexBufferLayout layoutLight;

		VertexArray vaoObject;
		VertexBuffer vboObject;
		VertexBufferLayout layoutObject;

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

			shaderObject.Gen("res/shaders/phong_light_shader.shader");
			shaderObject.Bind();

			shaderObject.SetUniformMat4f("u_projection", proj);
			shaderObject.SetUniformMat4f("u_viewport", view);
			shaderObject.SetUniformMat4f("u_model", model);

			shaderObject.SetUniform3fv("u_lightColor", lightColor);
			shaderObject.SetUniform1f("u_ambientStrength", ambientStrength);
			shaderObject.UnBind();
			//-----------
			vaoLight.Gen();
			vboLight.Gen(verticesLight, sizeof(verticesLight));
			layoutLight.Push<float>(3);
			vaoLight.AddBuffer(vboLight, layoutLight);
			vboLight.UnBind();
			vaoLight.UnBind();
			//-----------
			vaoObject.Gen();
			vboObject.Gen(verticesObject, sizeof(verticesObject));
			layoutObject.Push<float>(3);
			layoutObject.Push<float>(3);
			vaoObject.AddBuffer(vboObject, layoutObject);
			vaoObject.UnBind();
			vboObject.UnBind();

		}

		void draw_chapter()
		{

			//----------------------------
			view = camera.CameraTransformation();
			//---------------Lights--------------------------
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, lightPosition);
			model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
			vaoLight.Bind();
			shaderLight.Bind();
			shaderLight.SetUniformMat4f("u_model", model);
			shaderLight.SetUniformMat4f("u_viewport", view);
			shaderLight.SetUniform3fv("u_objectColor", lightColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(verticesLight) / (sizeof(verticesLight[0])));
			shaderLight.UnBind();
			vaoLight.UnBind();
			//-----------------object-------------------------
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePosition);
			float angle = 20.0f;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			vaoObject.Bind();
			shaderObject.Bind();
			shaderObject.SetUniformMat4f("u_model", model);
			shaderObject.SetUniformMat4f("u_viewport", view);
			shaderObject.SetUniform3fv("u_lightPosition", lightPosition);
			shaderObject.SetUniform3fv("u_objectColor", objectColor);
			glDrawArrays(GL_TRIANGLES, 0, sizeof(verticesObject) / (sizeof(verticesObject[0])));
			shaderObject.UnBind();
			vaoObject.UnBind();
			//---------------------------------------
		}

		void key_input_chapter(GLFWwindow* window)
		{
			camera.KeyInput(window);

			float speed_light_source = 0.05f;
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
				lightPosition += glm::vec3(-1, 0, 0) * speed_light_source;
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				lightPosition += glm::vec3(1, 0, 0) * speed_light_source;
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
				lightPosition += glm::vec3(0, 1, 0) * speed_light_source;
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
				lightPosition += glm::vec3(0, -1, 0) * speed_light_source;
			if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
				lightPosition += glm::vec3(0, 0, -1) * speed_light_source;
			if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
				lightPosition += glm::vec3(0, 0, 1) * speed_light_source;
		}

		void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos)
		{
			camera.MouseInput(window, xpos, ypos);
		}

	};
}

