#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

class gameOne {
private:

    float ex = -0.2f, ex2 = 0.0f, ey = 0.01f, ey2 = 0.2f;
    bool enemyA = true;

public:
    gameOne() {};
    ~gameOne() {};

    void gameOnePlay() {
        //플레이어
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {

            glBegin(GL_QUADS);
            glColor3f(0.1f, 0.1f, 0.4f);
            glVertex2f(-0.9f, 0.4f);
            glVertex2f(-0.7f, 0.4f);
            glVertex2f(-0.7f, 0.6f);
            glVertex2f(-0.9f, 0.6f);
            glEnd();
        }
        else
        {

            glBegin(GL_QUADS);
            glColor3f(0.1f, 0.1f, 0.4f);
            glVertex2f(-0.9f, 0.01f);
            glVertex2f(-0.7f, 0.01f);
            glVertex2f(-0.7f, 0.2f);
            glVertex2f(-0.9f, 0.2f);
            glEnd();
        }
        //플레이어

        //적
        if (enemyA == true) {                  //true면 적이 아래로 나오게 false면 적이 위로 나오게
            ey = 0.01f, ey2 = 0.2f;
            glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(ex, ey);
            glVertex2f(ex2, ey);
            glVertex2f(ex2, ey2);
            glVertex2f(ex, ey2);
            glEnd();
            if (ex <= -0.9f && ex2 <= -0.7f) {  // 일정거리 이상 가면 다시 원점으로 적을 옮깁니다.
                ex = -0.2f,
                ex2 = 0.0f,
                ey = 0.4f,
                ey2 = 0.6f;
                enemyA = false;
            }
        }
        if (enemyA == false) {
            ey = 0.4f, ey2 = 0.6f;
            glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(ex, ey);
            glVertex2f(ex2, ey);
            glVertex2f(ex2, ey2);
            glVertex2f(ex, ey2);
            glEnd();
            if (ex <= -0.9f && ex2 <= -0.7f) {
                ex = -0.2f,
                ex2 = 0.0f,
                ey = 0.01f,
                ey2 = 0.2f;
                enemyA = true;
            }
        }
        ex -= 0.004f; // 적의 좌표를 감소 시켜서 왼쪽을 이동
        ex2 -= 0.004f;
        //적


    }
};