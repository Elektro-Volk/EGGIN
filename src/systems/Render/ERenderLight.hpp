//
//  ERenderLight.hpp
//  EGGIN
//
//  Created by Elektro-Volk on 29/06/2018.
//
//

#pragma once
#include <irrlicht.h>
#include "ERenderLight.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class ERenderLight {
private:
    IMeshSceneNode* node;
public:
    ERenderLight();
    ~ERenderLight();
protected:

};

void setAmbientLight();
