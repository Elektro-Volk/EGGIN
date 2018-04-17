/*
host.cpp - main engine functions
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
#include "host.h"
#include "common.h"
#include "console.h"
#include "render/render.h"
#include "scenes.h"
#include "input.h"
#include "SDL2/SDL.h"

const string _version = "0.0.1";
float delta = 0.f;

/*
====================
bool initEngine();
Init all engine settings
====================
*/
bool initEngine(void)
{
  SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

  console::log("Initialization EGGIN V" + _version + "...");
	render::init();

  return true;
}

/*
====================
bool startEngine();
Start engine systems
====================
*/
bool startEngine(void)
{
  console::log("Starting engine...");
  render::start();

  return true;
}

/*
====================
bool frame();
Engine frame
====================
*/
long dt; // Delta
bool frame(void)
{
  dt = clock();
  // SDL_Window frame
  SDL_Event event;
	while (SDL_PollEvent(&event)) {
		//ImGui_ImplSdlGL2_ProcessEvent(&event);
		switch(event.type) {
			case SDL_QUIT: return false; break;
		}
	}

	input::frame();
	render::frame();
  scenesFrame();
  return true;
}

/*
====================
void postFrame();
Draw engine frame
====================
*/
void postFrame(void)
{
  render::drawFrame();
  delta = (clock() - dt) / 1000.f;
}
