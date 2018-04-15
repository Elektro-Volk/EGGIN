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
#include "console.h"
#include <iostream>

render::Window *render::win;

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
  win = new Window();

  // Setup ImGui binding
  //ImGui_ImplSdlGL2_Init(window);
  //ImGui::StyleColorsClassic();
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
