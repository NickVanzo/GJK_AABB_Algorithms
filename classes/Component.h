//
// Created by Nicolò Vanzo on 30/11/23.
//

#pragma once

#include "glm/glm/vec2.hpp"

class Component {
public:
    glm::vec2 getCenter();
    glm::vec2 center = glm::vec2(0,0);
};