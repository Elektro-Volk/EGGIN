#pragma once
#include "objects/GameObject.hpp"
#include "input.h"

class FreeCam : public GameObject
{
public:
	void update()
	{
		if (input::isKey(SDL_SCANCODE_W)) {
			this->position.z += cos(rotation.y / 57.3) / 2;
			this->position.x -= sin(rotation.y / 57.3) / 2;
		}
		if (input::isKey(SDL_SCANCODE_S)) {
			this->position.z -= cos(rotation.y / 57.3) / 2;
			this->position.x += sin(rotation.y / 57.3) / 2;
		}

		if (input::isKey(SDL_SCANCODE_A)) {
			this->position.z -= cos((rotation.y + 90) / 57.3) / 2;
			this->position.x += sin((rotation.y + 90) / 57.3) / 2;
		}
		if (input::isKey(SDL_SCANCODE_D)) {
			this->position.z += cos((rotation.y+90) / 57.3) / 2;
			this->position.x -= sin((rotation.y + 90) / 57.3) / 2;
		}

		if (input::isKey(SDL_SCANCODE_SPACE))
			this->position.y += 0.1f;
		if (input::isKey(SDL_SCANCODE_LSHIFT))
			this->position.y -= 0.1f;

		if (input::isKey(SDL_SCANCODE_LEFT))
			this->rotation.y -= 1.0f;
		if (input::isKey(SDL_SCANCODE_RIGHT))
			this->rotation.y += 1.0f;

		if (input::isKey(SDL_SCANCODE_UP))
			this->rotation.x += 1.0f;
		if (input::isKey(SDL_SCANCODE_DOWN))
			this->rotation.x -= 1.0f;
	}
	};
