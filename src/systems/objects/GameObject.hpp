/*
GameObject.hpp - base GameObject class
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
#include "utils/vec3.h"

class GameObject
{
public:
	vec3 position = vec3();
	vec3 rotation = vec3();

	GameObject* parent = nullptr;

	GameObject()
	{
	}

	virtual vec3 getLocalPosition()
	{
		return position;
	}

	virtual vec3 getGlobalPosition()
	{
		return parent ? parent->getGlobalPosition() + position : position;
	}

	virtual void setLocalPosition(vec3 position)
	{
		this->position = position;
	}

	virtual void setGlobalPosition(vec3 position)
	{
		this->position = parent ? parent->getGlobalPosition() + position : position;
	}

	virtual vec3 getLocalRotation()
	{
		return rotation;
	}

	virtual vec3 getGlobalRotation()
	{
		return parent ? parent->getGlobalRotation() + rotation : rotation;
	}

	virtual void setLocalRotation(vec3 rotation)
	{
		this->rotation = rotation;
	}

	virtual void setGlobalRotation(vec3 rotation)
	{
		this->rotation = parent ? parent->getGlobalPosition() + rotation : rotation;
	}
};
