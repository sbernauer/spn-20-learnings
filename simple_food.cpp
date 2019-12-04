#include "usercode.h"

bool init(Api *api)
{
    api->clearColors();

    api->addColor(40, 255, 0);
    api->addColor(20, 128, 0);
    api->addColor(10,  64, 0);
    api->addColor(20, 128, 0);

    return true;
}

bool step(Api *api)
{
    if (api->getFoodCount() == 0) {
        api->angle = 0;
        return true;
    }
    
    const IpcFoodInfo &seg = api->getFood()[0];
    api->angle = seg.dir;
    return true;
}
