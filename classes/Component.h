//
// Created by Nicolò Vanzo on 30/11/23.
//

#include "glm/vec2.hpp"
#pragma once

class Component {
public:
    glm::vec2 getCenter();
    glm::vec2 center = glm::vec2(0,0);
};