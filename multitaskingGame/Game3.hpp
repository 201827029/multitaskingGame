#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <iostream>

class gameThree {
private:

    float x = -0.9f, x2 = -0.7f, y = -0.9f, y2 = -0.7f;
    float ex = -0.3f, ex2 = -0.1f, ey = -0.3f, ey2 = -0.1f;
    int a;

public:

    gameThree() {};
    ~gameThree() {};

    void gameThreePlay() {

        srand(time(NULL)); //랜덤 숫자


        glBegin(GL_QUADS);
        glColor3f(0.1f, 0.1f, 0.4f);
        glVertex2f(x, y);
        glVertex2f(x2, y);
        glVertex2f(x2, y2);
        glVertex2f(x, y2);
        glEnd();


        if (GetAsyncKeyState(0x41) & 0x8000) //a
        {
            x -= 0.004f;
            x2 -= 0.004f;
        }

        if (GetAsyncKeyState(0x44) & 0x8000) //d
        {
            x += 0.004f;
            x2 += 0.004f;
        }

        if (x <= -1.0f) {
            x = -0.9f, x2 = -0.7f, y = -0.9f, y2 = -0.7f;
        }
        if (x2 >= -0.0f) {
            x = -0.3f, x2 = -0.1f, y = -0.9f, y2 = -0.7f;
        }

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(ex, ey); //사각형을 그리기 위해 4개의 점을 설정한다.  도형은 왼쪽 아래 꼭지점부터 반시계로 만들어짐
        glVertex2f(ex2, ey);
        glVertex2f(ex2, ey2);
        glVertex2f(ex, ey2);
        glEnd();
        ey -= 0.003f;
        ey2 -= 0.003f;

        if (ey <= -0.9f) {
            ex = -0.3f, ex2 = -0.1f, ey = -0.3f, ey2 = -0.1f;
        }



    }
};