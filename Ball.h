#pragma once
#include "GameObject.h"

class Ball : public GameObject {
private:

public:
    Ball();
    void Move(float fDeltaTime);
};
