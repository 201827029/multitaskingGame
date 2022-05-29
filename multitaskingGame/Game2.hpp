#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <iostream>

class gameTwo {
private:

    float x = 0.1f, x2 = 0.3f, y = 0.1f, y2 = 0.3f;
    float ex = 0.7f, ex2 = 0.9f, ey = 0.1f, ey2 = 0.3f;
    

public:

    gameTwo() {};
    ~gameTwo() {};

    void gameTwoPlay() {

        srand(time(NULL));
        int a;

        glBegin(GL_QUADS);
        glColor4f(0.1f, 0.1f, 0.7f, 0.6f);
        glVertex2f(x, y); //사각형을 그리기 위해 4개의 점을 설정한다.  도형은 왼쪽 아래 꼭지점부터 반시계로 만들어짐
        glVertex2f(x2, y);
        glVertex2f(x2, y2);
        glVertex2f(x, y2);
        glEnd();


        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y += 0.01f;
            y2 += 0.01f;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y -= 0.01f;
            y2 -= 0.01f;
        }

        if (y <= 0.01f) {
            x = 0.1f, x2 = 0.3f, y = 0.1f, y2 = 0.3f;
        }
        if (y2 >= 1.0f) {
            x = 0.1f, x2 = 0.3f, y = 0.7f, y2 = 0.9f;
        }


        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ex, ey); //사각형을 그리기 위해 4개의 점을 설정한다.  도형은 왼쪽 아래 꼭지점부터 반시계로 만들어짐
        glVertex2f(ex2, ey);
        glVertex2f(ex2, ey2);
        glVertex2f(ex, ey2);
        glEnd();
        ex -= 0.002f;
        ex2 -= 0.002f;

        if (ex <= 0.1f && ex2 <= 0.3f) {  // 일정거리 이상 가면 다시 원점으로 적을 옮깁니다.
            ex = 0.7f, ex2 = 0.9f, ey = 0.1f, ey2 = 0.3f;
            a = rand() % 10;
            std::cout << a;
        }

        if (a == 0, a == 1) {

        }
        if (a == 2, a == 3) {

        }
        if (a == 4, a == 5) {

        }
        if (a == 6, a == 7) {

        }
        if (a == 8, a == 9) {

        }



    }
};