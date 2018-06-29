//
//  ERender.hpp
//  EGGIN
//
//  Created by <author> on 29/06/2018.
//
//
#pragma once
#include <irrlicht.h>
#include "ERenderMesh.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class ERender {
private:
    IrrlichtDevice* m_device;
    IVideoDriver* m_driver;
    ISceneManager* m_smgr;

    friend class ERenderMesh;

    ISceneManager* getSceneManager();
public:
    ERender();
    void frame();
    ~ERender();
protected:

};

extern ERender* e_render;
