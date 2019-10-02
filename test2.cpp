#include "usercode.h"
using namespace std;
#include <bits/stdc++.h>
#include <math.h>

int rightAngleCounter = 0;
int circleEscaperSteps = 0;
int logCounter = 0;

double tmpX, tmpY;

bool init(Api *api)
{
    return true;
}

bool step(Api *api)
{
    
    double vecLengths[10];
    double vecDirs[10];

    int iterateTo = min(10, (int)api->getFoodCount());

    for (int i = 0; i < iterateTo; i++) {
        const IpcFoodInfo &food = api->getFood()[i];
        
        tmpX = sin(food.dir * (1 / (food.dist)) * food.val);
        tmpY = cos(food.dir * (1 / (food.dist)) * food.val);

        vecLengths[i] = sqrt(tmpX * tmpX + tmpY * tmpY);
        vecDirs[i] = atan2(tmpX, tmpY);
    }

    for (int i = 0; i < iterateTo; i++) {
        // stringstream message;
        // message << "vecLength: " << vecLengths[i] << " vecDir: " << vecDirs[i];
        // api->log(message.str().c_str());
    }

    double maxLength = 0;
    double finalRotation = 0;

    for (int i = 0; i < iterateTo; i++) {
        if (vecLengths[i] > maxLength) {
            maxLength = vecLengths[i];
            finalRotation = vecDirs[i];
        }
    }

    stringstream message;
    message << "finalRotation: " << finalRotation;
    api->log(message.str().c_str());

    
    api->angle = finalRotation;
    return true;
}
