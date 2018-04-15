/*
scenes.cpp - engine scene manager
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
#include "scenes.h"

Speedlist<Scene*> scenes;

/*
====================
void loadScene(bool unloadOld = true);
Load new scene
====================
*/
void loadScene(Scene *scene, bool unloadOld)
{
  if (unloadOld) {
    for (int i = 0; i < scenes.size(); i++)
      delete scenes[i];
    scenes.clear();
  }
  scenes.push(scene);
}

/*
====================
void scenesFrame();
Update all scenes
====================
*/
void scenesFrame()
{
  for (int i = 0; i < scenes.size(); i++)
      scenes[i]->update();
}
