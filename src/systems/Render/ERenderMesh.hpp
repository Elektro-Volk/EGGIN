//
//  ERenderMesh.hpp
//  EGGIN
//
//  Created by Elektro-Volk on 29/06/2018.
//
//
#pragma once
#include <irrlicht.h>
#include "ERenderFlags.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class ERenderMesh {
private:
    IMeshSceneNode* node;
public:
    ERenderMesh();
    void setMaterialFlag(ERenderFlags::Material flag, bool value);
    ~ERenderMesh();
protected:

};
