#include <iostream>
#include "host.h"


int main()
{
    initEngine();
    startEngine();
    while(frame()) {
      postFrame();
    }
    return 0;
}
