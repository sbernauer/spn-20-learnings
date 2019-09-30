#include "usercode.h"
using namespace std;
#include <bits/stdc++.h>
#include <math.h>

int rightAngleCounter = 0;
int circleEscaperSteps = 0;
int logCounter = 0;


bool init(Api *api)
{
    return true;
}

bool step(Api *api)
{
    if (circleEscaperSteps > 0) {
        circleEscaperSteps--;
        api->angle = 0;
        return true;
    }

    double movingX = 0;
    double movingY = 0;

    for(size_t i = 0; i < api->getFoodCount(); i++) {
        const IpcFoodInfo &food = api->getFood()[i];
     
        movingX += sin(food.dir * (1 / food.dist) * food.val);
        movingY += cos(food.dir * (1 / food.dist) * food.val);
    }

    double finalRotation = atan2(movingX, movingY);
    api->angle = finalRotation;


    for(size_t i = 0; i < api->getSegmentCount(); i++) {
        const IpcSegmentInfo &seg = api->getSegments()[i];
     
        if(!seg.is_self && seg.dist < 20) {
            api->log("Oh no, I'm going to die!");
            break;
        }
    }




    auto info = api->getSelfInfo();




    // stringstream message;
    // message << "finalRotation: " << finalRotation;
    // api->log(message.str().c_str());
    return true;
}
