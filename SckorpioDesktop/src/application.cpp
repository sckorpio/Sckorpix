#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <fstream>
#include <string>
#include <sstream>

#include "chapters\chapters.h"
#include "chapters\chapter.h"

void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

//################# EDIT CHAPTER HERE ############################
chapter* m_chapter = new cedars_byte::ball_game();
//################################################################

void init()
{
    printf("Vendor graphic card: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version GL: %s\n", glGetString(GL_VERSION));
    printf("Version GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    if (glewInit() != GLEW_OK)
        std::cout << "GLEW_NOT_OK" << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    init();
   
    //-----------------

    m_chapter->init_chapter();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);
       

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        m_chapter->draw_chapter();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    m_chapter->key_input_chapter(window);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    m_chapter->mouse_input_chapter(window, xpos, ypos);
}


