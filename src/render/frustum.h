/*
frustum.h - frustum culling
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
#include "utils/vec3.h"
#include "GL/gl.h"

namespace frustum {
  extern float frustum[6][4];

  void extract();
  bool pointInFrustum( float x, float y, float z );
  bool sphereInFrustum( float x, float y, float z, float radius );
  bool cubeInFrustum( float x, float y, float z, float size );
}
