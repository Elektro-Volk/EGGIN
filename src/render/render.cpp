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
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include "render.h"
#include "console.h"
#include "draw.h"
#include "imgui/imgui.h"
#include "imgui/togl.h"
#include <SDL2/SDL_image.h>

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
  ImGui_ImplSdlGL2_Init(win->sdlwin);
  ImGui::StyleColorsClassic();
}

/*
====================
void render::frame();
Clear frame
====================
*/
void render::frame()
{
  ImGui_ImplSdlGL2_NewFrame(win->sdlwin);
  //ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);

  glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // включаем тест глубины
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f, (float) win->width / (float) win->height, 0.1f, 100.0f); // настраиваем трехмерную перспективу
	glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим
  glLoadIdentity();
  if (cam) cam->frame();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  draw::flush();
}

/*
====================
void render::drawFrame();
Draw frame
====================
*/
void render::drawFrame()
{
  glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
  //glClear(GL_COLOR_BUFFER_BIT);
  ImGui::Render();
  SDL_GL_SwapWindow(win->sdlwin);
}

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

/*
====================
int render::loadTexture(char* name, bool minmap, texparam* params, short int pcount);
Load texture from name
====================
*/
int render::loadTexture(string name, bool mipmap, std::vector<texparam> params)
{
  console::log("Loading " + name + "...");
  SDL_Surface* surf = IMG_Load(("./textures/" + name).c_str());

	GLuint format = surf->format->Rmask == 0x000000ff ? GL_RGBA : GL_BGRA;
	GLuint tid;
	glGenTextures(1, &tid);

	glBindTexture(GL_TEXTURE_2D, tid);
	glTexImage2D(GL_TEXTURE_2D, 0, surf->format->BytesPerPixel, surf->w, surf->h, 0, format, GL_UNSIGNED_BYTE, surf->pixels);
  SDL_FreeSurface(surf);

  // Default
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  for (int i = 0; i < params.size(); i++)
    glTexParameteri(GL_TEXTURE_2D, params[i].param, params[i].value);
  if (mipmap) glGenerateMipmap(GL_TEXTURE_2D);

  return tid;
}
