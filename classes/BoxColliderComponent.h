//
// Created by Nicolò Vanzo on 30/11/23.
//

#pragma once
#include "string"
#include "Component.h"
class BoxColliderComponent: public Component {
public:
    int horizontalOffset = 1;
    int verticalOffset = 1;
    int getHorizontalOffset();
    int getVerticalOffset();
    void setHorizontal(int);
    void setVertical(int);
};


