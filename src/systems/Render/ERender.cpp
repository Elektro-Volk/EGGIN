//
//  ERender.cpp
//  EGGIN
//
//  Created by Elektro-Volk on 29/06/2018.
//
//

#include "core/EGGIN.hpp"
#include "core/EConsole.hpp"
#include "ERender.hpp"

ERender* e_render;

/* Return RenderSceneManager */
ISceneManager* ERender::getSceneManager()
{
    return m_smgr;
}

/* Init and start Render engine */
ERender::ERender()
{
    e_console->log("Render", "Starting render engine...");

    m_device = createDevice(EDT_OPENGL, dimension2du(800, 600), 16, false, false, false, 0);
    m_device->setWindowCaption(L"EGGIN");

    m_driver = m_device->getVideoDriver();
    m_smgr = m_device->getSceneManager();

    m_smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
}

/* Render frame */
void ERender::frame()
{
    if (!m_device->run()) EGGIN::shutdown();
    m_driver->beginScene(true, true, SColor(0,20,0,0));
    m_smgr->drawAll();
    m_driver->endScene();
}

/* Shutdown Render */
ERender::~ERender()
{
    m_device->drop();
}
