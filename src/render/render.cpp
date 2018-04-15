/*
render.cpp - engine render
Copyright (C) 2018 Elektro-Volk
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#include "render.h"
#include "console.h"
#include <iostream>

render::Window *render::win;
Camera *render::cam;

/*
====================
void render::init();
Init render settings
====================
*/
void render::init()
{

}

/*
====================
void render::start();
Start render engine
====================
*/
void render::start()
{
  // Set attributes
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

  SDL_DisplayMode current;
  SDL_GetCurrentDisplayMode(0, &current);
  // Create window
  win = new Window("EGGIN", 800, 600);

  // Setup ImGui binding
  //ImGui_ImplSdlGL2_Init(window);
  //ImGui::StyleColorsClassic();
}

/*
====================
void render::frame();
Clear frame
====================
*/
void render::frame()
{
  //ImGui_ImplSdlGL2_NewFrame(window);
  //ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
	//glClearColor(rand()%255/255.f, rand()%255/255.f, rand()%255/255.f, 0.0f); // устанавливаем фоновый цвет на черный
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // включаем тест глубины
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, (float) 1280 / (float) 720, 0.1f, 100.0f); // настраиваем трехмерную перспективу
	glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим
  glLoadIdentity();
  if (cam) cam->frame();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/*
====================
void render::drawFrame();
Draw frame
====================
*/
void render::drawFrame()
{
  //glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
  //glClear(GL_COLOR_BUFFER_BIT);
  //ImGui::Render();
  SDL_GL_SwapWindow(win->sdlwin);
}

/******** render::Window **********/
/*
====================
Window::Window (char *name, int w, int h);
Create window
====================
*/
render::Window::Window (char *name, int w, int h)
{
  width = w; height = h;
  sdlwin = SDL_CreateWindow("EGGIN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
  context = SDL_GL_CreateContext(sdlwin);
}
