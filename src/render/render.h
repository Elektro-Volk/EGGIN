/*
render.h - engine render
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
#pragma once
#include "common.h"
#include "SDL2/SDL.h"
#include "GL/gl.h"
#include <GL/glu.h>

namespace render {
  class Window {
  public:
    int width, height;
    SDL_Window *sdlwin;
    SDL_GLContext context;

    Window (char *name, int w, int h);
    ~Window();
  };

  extern Window *win;

  void init();
  void start();
}
