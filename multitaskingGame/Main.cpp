#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Game1.hpp"
#include "Game2.hpp"
#include "Game3.hpp"
#include "startGame.hpp"

#pragma comment(lib, "opengl32") //library 파일의 경로를 명시적으로 나타낼 때 쓰인다.

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);//파일에 문자열을 쓰는 함수.    stderr -기본 출력장치(모니터) -에러
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)//기말
{
    GLFWwindow* window;
    startGame gameStart;
    gameOne game1;
    bool startBool = false;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//윈도우를 만든다.

    if (!window)
    {
        glfwTerminate();//사용된 메모리를 삭제하는 함수이다.
                        //프로그램이 종료되기 직전에 반드시 호출해야 한다.
        exit(EXIT_FAILURE); //return 1; 과 같다. 비정상적으로 프로그램이 종료 된다면
    }

    glfwMakeContextCurrent(window);//Window를 등록하는 함수이며,
                                   //등록되면 Thread로 설정되어 사용된다. Thread - 작업을 수행하는 주체
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))//현재 Window가 종료되었는지 확인하는 함수
    {
        
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//프레임버퍼의 크기를 가지고 온다
        ratio = width / (float)height;

        glClearColor(0.5f, 0.8f, 0.9f, 1); // glClearColor - 초기화하는 색을 설정하는 함수
        glClear(GL_COLOR_BUFFER_BIT); // glClear - glClearColor 에서 설정된 색상으로 화면을 지우는 함수


        //게임의 경계선 입니다.
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
        //게임의 경계선 입니다.
        

        if (!startBool) 
        {

            if (GetAsyncKeyState(0x53) & 0x8000)    //S 눌러 게임 시작
            {
                startBool = true;
            }

        }


        if(startBool)
            gameStart.startgame();

                                //게임 실행 중이 아닐 때 나오는 화면



        



        glfwSwapBuffers(window);//이전 Frame에 그려진 Buffer와 현재 Frame에 그려진 Buffer를 Swap
        glfwPollEvents();//현재 Frame의 입력 및 출력이 되었는지 확인
    }

    glfwDestroyWindow(window);
    glfwTerminate();//사용된 메모리를 삭제하는 함수이다.
                    //프로그램이 종료되기 직전에 반드시 호출해야 한다.
    exit(EXIT_SUCCESS); //return 0; 과 같다. 성공적으로 프로그램이 종료 된다면
}