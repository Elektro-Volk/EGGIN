/*
draw.cpp - simple draw
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
#include "draw.h"
#include "imgui/imgui.h"

int draw::_nVerts = 0;
int draw::_drawCalls = 0;
int draw::nVerts = 0;
int draw::drawCalls = 0;

/*
====================
void draw::simple(GLenum mode, float *vertices, float *uvs, int size);
Draw mesh
====================
*/
void draw::simple(GLenum mode, float *vertices, float *uvs, int size)
{
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glTexCoordPointer(2, GL_FLOAT, 0, uvs);
  glDrawArrays(mode, 0, size);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  _drawCalls++; _nVerts += size;
}

/*
====================
void draw::posed(GLenum mode, float *vertices, float *uvs, int size, vec3 &position);
Draw mesh posed
====================
*/
void draw::posed(GLenum mode, float *vertices, float *uvs, int size, vec3 &position)
{
  glTranslatef(position.x, position.y, position.z);
  draw::simple(mode, vertices, uvs, size);
  glTranslatef(-position.x, -position.y, -position.z);
}

/*
====================
void draw::posRot(GLenum mode, float *vertices, float *uvs, int size, vec3 &position, vec3 &rotation);
Draw mesh posed and rotated
====================
*/
void draw::posRot(GLenum mode, float *vertices, float *uvs, int size, vec3 &position, vec3 &rotation)
{
  // TODO
}

/*
====================
void draw::flush();
Flush drawCalls and nVerts
====================
*/
extern float delta;
bool render_debug = true;
void draw::flush()
{
  nVerts = _nVerts;
  drawCalls = _drawCalls;
  _nVerts = 0; _drawCalls = 0;

  // Debug
  if (!render_debug) return;
  ImGui::Begin("Render debug", &render_debug);
  ImGui::Text("Vertices: %d", nVerts);
  ImGui::Text("DrawCalls: %d", drawCalls);
  ImGui::Text("Delta: %f", delta);
  ImGui::Text("FPS: %f", 1.f / delta);
  ImGui::End();
}
