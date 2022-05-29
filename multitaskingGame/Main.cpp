#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Game1.hpp"
#include "Game2.hpp"
#include "Game3.hpp"
#include "startGame.hpp"

#pragma comment(lib, "opengl32") //library ������ ��θ� ��������� ��Ÿ�� �� ���δ�.

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);//���Ͽ� ���ڿ��� ���� �Լ�.    stderr -�⺻ �����ġ(�����) -����
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)//�⸻
{
    GLFWwindow* window;
    startGame gameStart;
    gameOne game1;
    bool startBool = false;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//�����츦 �����.

    if (!window)
    {
        glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��̴�.
                        //���α׷��� ����Ǳ� ������ �ݵ�� ȣ���ؾ� �Ѵ�.
        exit(EXIT_FAILURE); //return 1; �� ����. ������������ ���α׷��� ���� �ȴٸ�
    }

    glfwMakeContextCurrent(window);//Window�� ����ϴ� �Լ��̸�,
                                   //��ϵǸ� Thread�� �����Ǿ� ���ȴ�. Thread - �۾��� �����ϴ� ��ü
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))//���� Window�� ����Ǿ����� Ȯ���ϴ� �Լ�
    {
        
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//�����ӹ����� ũ�⸦ ������ �´�
        ratio = width / (float)height;

        glClearColor(0.5f, 0.8f, 0.9f, 1); // glClearColor - �ʱ�ȭ�ϴ� ���� �����ϴ� �Լ�
        glClear(GL_COLOR_BUFFER_BIT); // glClear - glClearColor ���� ������ �������� ȭ���� ����� �Լ�


        //������ ��輱 �Դϴ�.
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-20.0f, -0.01f);
        glVertex2f(20.0f, -0.01f);
        glVertex2f(20.0f, 0.01f);
        glVertex2f(-20.0f, 0.01f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.01f, -20.0f);
        glVertex2f(0.01f, -20.0f);
        glVertex2f(0.01f, 20.0f);
        glVertex2f(-0.01f, 20.0f);
        glEnd();
        //������ ��輱 �Դϴ�.
        

        if (!startBool) 
        {

            if (GetAsyncKeyState(0x53) & 0x8000)    //S ���� ���� ����
            {
                startBool = true;
            }

        }


        if(startBool)
            gameStart.startgame();

                                //���� ���� ���� �ƴ� �� ������ ȭ��



        



        glfwSwapBuffers(window);//���� Frame�� �׷��� Buffer�� ���� Frame�� �׷��� Buffer�� Swap
        glfwPollEvents();//���� Frame�� �Է� �� ����� �Ǿ����� Ȯ��
    }

    glfwDestroyWindow(window);
    glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��̴�.
                    //���α׷��� ����Ǳ� ������ �ݵ�� ȣ���ؾ� �Ѵ�.
    exit(EXIT_SUCCESS); //return 0; �� ����. ���������� ���α׷��� ���� �ȴٸ�
}