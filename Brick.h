#pragma once
#include "GameObject.h"

class Brick : public GameObject {
private:
    std::vector<Brick*> life;
    
public:
    Brick();
};

