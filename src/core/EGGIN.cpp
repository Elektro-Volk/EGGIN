//
//  EGGIN.cpp
//  EGGIN
//
//  Created by Elektro-Volk on 29/06/2018.
//
//

#include "EGGIN.hpp"
#include "systems/Render/ERender.hpp"

bool EGGIN::isWork = true;

int EGGIN::initEngine()
{
    e_render = new ERender();

    return 0;
}

void EGGIN::frame()
{
    e_render->frame();
}

void EGGIN::shutdown()
{
    isWork = false;
}
