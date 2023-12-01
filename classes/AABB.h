//
// Created by Nicolò Vanzo on 30/11/23.
//
#include<string>
#include "Component.h"
#pragma once

namespace ConcreteStrategyAABB {
    class AABB {
    public:
        bool checkCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2);
    };
}
