//
//  ERenderMesh.cpp
//  EGGIN
//
//  Created by Elektro-Volk on 29/06/2018.
//
//
#include "ERender.hpp"
#include "ERenderMesh.hpp"

ERenderMesh::ERenderMesh()
{
    node = e_render->getSceneManager()->addCubeSceneNode();
    setMaterialFlag(ERenderFlags::Material::LIGHTING, false);
    //wall->setMaterialTexture(0, driver->getTexture("../../media/wall.jpg"));
}

void ERenderMesh::setMaterialFlag(ERenderFlags::Material flag, bool value)
{
    node->setMaterialFlag((irr::video::E_MATERIAL_FLAG)flag, value);
}

ERenderMesh::~ERenderMesh()
{

}
