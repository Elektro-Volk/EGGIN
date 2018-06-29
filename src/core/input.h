/*
input.h - input engine
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

#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_scancode.h"
#include "SDL2/SDL_mouse.h"

namespace input
{
	extern int curX, curY;
	extern int spdX, spdY;
	extern bool lockCursor;

	void frame();
	bool isKey(int code);
	bool isKeyChanged(int code, bool pressed);
	bool isMouseKeyChanged(int code, bool pressed);
	bool isMouseKey(int code);
	void getMouseSpeed(int &x, int &y);
	void setLockCursor(bool lock);
}
