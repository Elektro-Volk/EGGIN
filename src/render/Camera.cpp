/*
Camera.cpp - render camera
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
#include "Camera.h"
#include "render.h"

/*
====================
void Camera::frame();
Setup camera position
====================
*/
void Camera::frame()
{
  float rad = 57.2957;

  vec3 P = getGlobalPosition();
  vec3 R = getGlobalRotation();
	gluLookAt(P.x, P.y, P.z, P.x - sin(R.y / rad), P.y + tan(R.x / rad), P.z + cos(R.y / rad), 0, 1, 0);
}
