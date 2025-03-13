#pragma once
#define pragma once
#include "../chapter.h"

//#################################################################
//CHAPTER-Game
//Making a Game for CedarsByte
//
namespace cedars_byte {
	class ball_game : public chapter
	{
		//------------------grass background------------------------------------------
		float vertices_grass[4][4] = {0.0f   ,0.0f,   0.0f ,0.0f,			//A
									600.0f ,0.0f,   1.0f ,0.0f,				//B
									600.0f ,600.0f, 1.0f ,1.0f,				//C
									0.0f   ,600.0f, 0.0f ,1.0f };			//D


		unsigned int indices_grass[6] = { 0, 1, 2,  // first Triangle
										  2, 3, 0 };  // second Triangle

		//--------------------brick walls--------------------------------------------
		float vertices_brick[8][4] = {0.0f   ,0.0f,  0.0f ,0.0f,				//A
									0.0f ,600.0f,   0.0f ,1.0f,				//B
									600.0f ,600.0f, 1.0f ,1.0f,				//C
									600.0f   ,0.0f, 1.0f ,0.0f,				//D
									540.0f   ,0.0f, 0.9f ,0.0f,				//E
									540.0f ,540.0f, 0.9f ,0.9f,				//F
									60.0f ,540.0f, 0.1f ,0.9f,				//G
									60.0f ,0.0f,	0.1f ,0.0f };			//H


		unsigned int indices_brick[18] = { 0, 1, 6,    
										  0, 7, 6,
										  1, 6, 5,    
										  1, 5, 2,
										  5, 2, 4,    
										  2, 4, 3 };

		//-------------------------ball------------------------------------
		glm::vec3 pos_ball = glm::vec3(300.0f, 300.0f, 0.0f);
		glm::vec3 velocity_ball = glm::vec3(0.0f, -15.0f, 0.0f);
		float radius_ball = 50.0f;

		float vertices_ball[4][4] = { 0.0f   ,0.0f,   0.0f ,0.0f,			//A
									600.0f ,0.0f,   1.0f ,0.0f,				//B
									600.0f ,600.0f, 1.0f ,1.0f,				//C
									0.0f   ,600.0f, 0.0f ,1.0f };			//D


		unsigned int indices_ball[6] = { 0, 1, 2,  // first Triangle
										  2, 3, 0 };  // second Triangle
		
		//-----------------------plank-------------------------------------
		glm::vec3 pos_plank = glm::vec3(200.0f, 100.0f, 0.0f);
		glm::vec3 velocity_plank = glm::vec3(0.0f, 0.0f, 0.0f);
		float acceleration_plank = 5.0f;
		float width_plank = 200.0f;
		float height_plank = 40.0f;

		float vertices_plank[4][4] = { 0.0f   ,0.0f,   0.0f ,0.0f,			    //A
									   600.0f ,0.0f,   1.0f ,0.0f,				//B
									   600.0f ,600.0f, 1.0f ,1.0f,				//C
									   0.0f   ,600.0f, 0.0f ,1.0f };			//D


		unsigned int indices_plank[6] = { 0, 1, 2,  // first Triangle
										  2, 3, 0 };  // second Triangle

		//------------------------------------------------------------

		VertexBufferLayout layout;
		
		VertexArray vao_grass;
		VertexBuffer vbo_grass;
		IndexBuffer ebo_grass;

		VertexArray vao_brick;
		VertexBuffer vbo_brick;
		IndexBuffer ebo_brick;

		VertexArray vao_ball;
		VertexBuffer vbo_ball;
		IndexBuffer ebo_ball;

		VertexArray vao_plank;
		VertexBuffer vbo_plank;
		IndexBuffer ebo_plank;
		
		Texture textureBrick;
		Texture textureGrass;
		Texture textureBall;
		Texture texturePlank;

		Shader shader;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;

		//---------------------physics---------------------------------------------

		float curr_t = 0.0f;
		float prev_t = 0.0f;
		float gravity = 5.0f;

		//-----------------------------------------------------------------

		void init_chapter()
		{
			model = glm::mat4(1.0f);
			view = glm::mat4(1.0f);
			proj = glm::mat4(1.0f);

			//for projection

			glm::mat4 ortho = glm::ortho(0.0f, (float)(width), 0.0f, (float)(height), -1.0f, 1.0f);
			proj = ortho;
			
			//--------

			shader.Gen("res/shaders/texture_mvp_shader.shader");
			shader.Bind();

			shader.SetUniformMat4f("u_projection", proj);
			shader.SetUniformMat4f("u_viewport", view);
			shader.SetUniformMat4f("u_model", model);
			//---------------------------
			textureBrick.Gen("res/textures/brick.jpg");
			textureGrass.Gen("res/textures/grass.png");
			textureBall.Gen("res/textures/ball.png");
			texturePlank.Gen("res/textures/wood2.jpg");
			//----------------------------
			
			layout.Push<float>(2);
			layout.Push<float>(2);
			//--------------grass--------------
			vao_grass.Gen();
			vbo_grass.Gen(vertices_grass, sizeof(vertices_grass));
			ebo_grass.Gen(indices_grass, sizeof(indices_grass));
			vao_grass.AddBuffer(vbo_grass, layout);

			vao_grass.UnBind();
			vbo_grass.UnBind();
			ebo_grass.UnBind();
			//---------------bricks---------------
			vao_brick.Gen();
			vbo_brick.Gen(vertices_brick, sizeof(vertices_brick));
			ebo_brick.Gen(indices_brick, sizeof(indices_brick));
			vao_brick.AddBuffer(vbo_brick, layout);

			vao_brick.UnBind();
			vbo_brick.UnBind();
			ebo_brick.UnBind();
			//----------------ball-------------
			
			vao_ball.Gen();
			vbo_ball.Gen(vertices_ball, sizeof(vertices_ball));
			ebo_ball.Gen(indices_ball, sizeof(indices_ball));
			vao_ball.AddBuffer(vbo_ball, layout);

			vao_ball.UnBind();
			vbo_ball.UnBind();
			ebo_ball.UnBind();
			//-----------------plank------------
			vao_plank.Gen();
			vbo_plank.Gen(vertices_plank, sizeof(vertices_plank));
			ebo_plank.Gen(indices_plank, sizeof(indices_plank));
			vao_plank.AddBuffer(vbo_plank, layout);

			vao_plank.UnBind();
			vbo_plank.UnBind();
			ebo_plank.UnBind();
			//-----------------------------

			shader.UnBind();
		}

		void draw_chapter()
		{
			physicsCalculation();
			
			//----------------------------
			drawPlank();
			drawBall();
			drawBricks();
			drawGrass();
			
			//---------------------------------------

		}

		void key_input_chapter(GLFWwindow* window)
		{
			if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
				velocity_plank += glm::vec3(-1, 0, 0) * acceleration_plank;
			if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
				velocity_plank += glm::vec3(1, 0, 0) * acceleration_plank;

		}

		void mouse_input_chapter(GLFWwindow* window, double xpos, double ypos)
		{

		}
		//----------------------------------------------

		void physicsCalculation()
		{
			float curr_t = (float)glfwGetTime();
			
			float delta_t = curr_t - prev_t;
			
			//-----PLANK--------------------------------------
			
			pos_plank = pos_plank + velocity_plank * delta_t;

			//----plank_brick--------
			if (pos_plank.x <= 60)   // hitting left wall
			{
				velocity_plank = glm::vec3(0.0f, 0.0f, 0.0f);
				pos_plank.x = 60.0f;
			}
			
			if((pos_plank.x + width_plank) >= 540) // hitting right wall
			{
				velocity_plank = glm::vec3(0.0f, 0.0f, 0.0f);
				pos_plank.x = 540.0f - width_plank;
			}
				
			//--------BALL-----------------------------------

			//velocity_ball.y = velocity_ball.y - gravity * delta_t;
			pos_ball = pos_ball + velocity_ball * delta_t;

			//-----ball-plank-----
			float friction = 0.4f;
			if ((pos_ball.y) <= (pos_plank.y + height_plank))
			{
				float centre_ball_x = pos_ball.x + radius_ball;
				float centre_plank_x = pos_plank.x + width_plank / 2.0f;
				if (abs(centre_ball_x - centre_plank_x) <= (width_plank / 2.0f + radius_ball))
				{
					velocity_ball.y *= -1;
					velocity_ball.y += abs(velocity_plank.x * (1 - friction));
					velocity_ball.x += velocity_plank.x * (1 - friction);
				}
			}

			//-----ball-brick-----
			std::cout << pos_ball.x << " , " << pos_ball.y << std::endl;
			if(pos_ball.x <= 60)
				velocity_ball.x *= -1;

			if(pos_ball.x + radius_ball >= 540)
				velocity_ball.x *= -1;

			if (pos_ball.y + radius_ball >= 540)
				velocity_ball.y *= -1;


			

			prev_t = curr_t;
			
		}

		void drawGrass()
		{
			shader.Bind();
			textureGrass.Bind();
			shader.SetUniform1i("u_Texture", 0);
			vao_grass.Bind();

			glm::mat4 trans = glm::mat4(1.0f);
			model = trans;
			shader.SetUniformMat4f("u_model", model);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

			vao_grass.UnBind();
			shader.UnBind();
		}

		void drawBricks()
		{
			shader.Bind();
			textureBrick.Bind();
			shader.SetUniform1i("u_Texture", 0);
			vao_brick.Bind();

			glm::mat4 trans = glm::mat4(1.0f);
			model = trans;
			shader.SetUniformMat4f("u_model", model);
			glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, nullptr);

			vao_brick.UnBind();
			shader.UnBind();
		}

		void drawBall()
		{
			shader.Bind();
			textureBall.Bind();
			shader.SetUniform1i("u_Texture", 0);
			vao_ball.Bind();

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::translate(trans, pos_ball);
			trans = glm::scale(trans, glm::vec3(radius_ball/width, radius_ball/height, 1.0f));
			model = trans;
			shader.SetUniformMat4f("u_model", model);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

			vao_ball.UnBind();
			shader.UnBind();
		}

		void drawPlank()
		{
			shader.Bind();
			texturePlank.Bind();
			shader.SetUniform1i("u_Texture", 0);
			vao_plank.Bind();

			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::translate(trans, pos_plank);
			trans = glm::scale(trans, glm::vec3(width_plank / width, height_plank / height, 1.0f));
			model = trans;
			shader.SetUniformMat4f("u_model", model);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

			vao_plank.UnBind();
			shader.UnBind();
		}



	};
}

