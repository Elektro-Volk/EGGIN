/*
input.cpp - input engine
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
#include "input.h"
#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_mouse.h"
#include "render/imgui/imgui.h"
#include "render/render.h"
//#include <windows.h>
#include <iostream>

const Uint8 *keystate;
Uint8 old_keystate[SDL_NUM_SCANCODES];
Uint8 mousestate;
Uint8 old_mousestate;
int input::curX, input::curY;
int input::spdX, input::spdY;
bool input::lockCursor;

void input::frame()
{
	old_mousestate = mousestate;

	keystate = SDL_GetKeyboardState(0);
	mousestate = SDL_GetMouseState(NULL, NULL);
	// Mouse pos
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	spdX = mx - curX;
	spdY = my - curY;

	curX = mx;
	curY = my;

	if (lockCursor) {
		////ImVec2 p = ImGui::GetWindowPos();
		curX = render::win->width / 2;
		curY = render::win->height / 2;
		////glutWarpPointer(curX, curY);
		SDL_WarpMouseInWindow(render::win->sdlwin, curX, curY);

		//SetCursorPos(curX,curY); // Windows
	}
}

bool input::isKey(int code)
{
	return keystate[code];
}

bool input::isKeyChanged(int code, bool pressed)
{
	bool ok = old_keystate[code] != keystate[code] && keystate[code] == pressed;
	old_keystate[code] = keystate[code];
	return ok;
}

bool input::isMouseKeyChanged(int code, bool pressed)
{
	return ((mousestate & SDL_BUTTON(code)) != (old_mousestate & SDL_BUTTON(code)))
		&& ((bool)(mousestate & SDL_BUTTON(code)) == pressed);
}

bool input::isMouseKey(int code)
{
	return mousestate & SDL_BUTTON(code);
}

void input::getMouseSpeed(int &x, int &y)
{
	x = spdX;
	y = spdY;
}

void input::setLockCursor(bool lock)
{
	lockCursor = lock;
	//ShowCursor(!lock);
}
