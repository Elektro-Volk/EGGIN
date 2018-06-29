#include <iostream>
#include "core/EGGIN.hpp"
#include "systems/Render/ERender.hpp"

int main()
{
    EGGIN::initEngine();

    new ERenderMesh();

    while (EGGIN::isWork) { EGGIN::frame(); }
    return 0;
}
