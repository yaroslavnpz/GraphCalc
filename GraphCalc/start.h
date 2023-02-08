#pragma once

#ifndef START_H
#define START_H

#ifdef _WIN32 || _WIN64
#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#endif


#include <SDL2/SDL.h>
//#include <glad/glad.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include "stb_image.h"
#include "kalk.h"
using namespace std;


struct mouse {//структура указателя мыши
    int x, y;
};

int re_menu = 0;

class Window {//класс для окна
private:

public:
    SDL_Window* w;//окно

    SDL_Event e;//события

    SDL_GLContext glcontext;

    mouse m;//мышь

    int x, y;//размеры

    Window(const char name[], int xx, int yy) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            exit(1);
        }

        x = xx;
        y = yy;

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

        w = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        glcontext = SDL_GL_CreateContext(w);
        //gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
        if (w == NULL) {
            exit(1);
        }
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();
        gluPerspective(45.0f, double(x) / double(y), 0.1f, 100.0f);//gluPerspective(45.0f, 1000.0 / 500.0, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
        /*********************************************/
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        ///////////////////////////////////////////////////////////
        glEnable(GL_COLOR_MATERIAL);


        //glEnable(GL_LIGHTING);

    }
    /*******************************************************************************************************************/
    ~Window() {
        SDL_DestroyWindow(w);
        SDL_GL_DeleteContext(glcontext);
        SDL_Quit();
    }
    /*******************************************************************************************************************/
};



double map(double v, double max, double max1) {
    v = v / (max);
    v = v * (max1);
    return v;
}

double pole_x, pole_y;


#endif