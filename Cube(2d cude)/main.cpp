#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

GLfloat rtri;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwWindowShouldClose(window);
}


int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW FAILED";
    }
    std::cout << "GLFW START, LETS MAKE MAGIC!" << std::endl;
    GLFWwindow* window = glfwCreateWindow(640, 480, "Test GLFW", NULL, NULL);
    //Создаю контекст
    glfwMakeContextCurrent(window);
    gladLoadGL();
    std::cout << "OpenGL load" << std::endl;
    //Указываю обработчик inputа
    glfwSetKeyCallback(window, key_callback);
    std::cout << "Input configure" << std::endl;
    int cout = 0;
    //Просто бесконечный цикл чтобы окно существовало
    while (!glfwWindowShouldClose(window))
    {
        //Вызовы OpenGL для настройки окна и очистки кадра
        glViewport(0, 0, 640, 480);
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0f, 0.0f); glVertex2f(0, 0);
        glColor3f(0.0, 1.0f, 0.0f); glVertex2f(0.5f, 0);
        glColor3f(0.0, 0.0f, 1.0f); glVertex2f(0, 0.5f);

        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, 0);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.5f, 0.5f);
        glEnd();
        glLoadIdentity();
        glPopMatrix();
        rtri=0.8f;
        glRotatef(rtri,0.0f,1.0f,1.0f);
        //Ну и последнии операции для смены кадра
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}


//Coded by Genius
//My steam: https://steamcommunity.com/profiles/76561199850375269/
