
#define GLFW_DLL
#define GLFW_DLL
#include <iostream>
#include "glew-2.1.0\include\GL\glew.h"
#include "glfw-3.4.bin.WIN64\include\GLFW\glfw3.h"

int main()
{
    std::cout << "Hello World!\n";
    glfwInit();
    if (!glfwInit()) {
        fprintf(stderr, "ERROR GLFW Init: \n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1.0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0.0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* Okno;
    Okno = glfwCreateWindow(512, 512, "Okno", NULL, NULL);

    if (!Okno) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(Okno);

    glewInit();
    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR GLEW Init: \n", glewGetErrorString(ret));
        return -2;
    }

    while (!glfwWindowShouldClose(Okno)) {

        glClearColor(0.4f, 0.5f, 1.0f, 1.0f); // фон вариант 29
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 0.2f); // цвет фигуры вариант 29

        // пятиугольник
        glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.6f);
        glVertex2f(0.57f, 0.18f);
        glVertex2f(0.35f, -0.49f);
        glVertex2f(-0.35f, -0.49f);
        glVertex2f(-0.57f, 0.18f);
        glEnd();

        glfwSwapBuffers(Okno);
        glfwPollEvents();

    }
    glfwTerminate();

}
