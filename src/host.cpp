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
#include "SDL2/SDL.h"

const string _version = "0.0.1";

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
	//render::init();
}

/*
====================
bool startEngine();
Start engine systems
====================
*/
bool startEngine(void)
{

}

/*
====================
bool frame();
Engine frame
====================
*/
bool frame(void)
{

}

/*
====================
void postFrame();
Draw engine frame
====================
*/
void postFrame(void)
{

}
