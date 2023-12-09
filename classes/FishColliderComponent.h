#pragma once
#include "string"
#include "list"
#include "Component.h"
#include "glm/glm/detail/type_vec.hpp"

class FishColliderComponent: public Component {
public:
    std::list<glm::vec2> vertexes = std::list<glm::vec2>(); //was "nodes"
    glm::vec2 center = glm::vec2(0, 1);
    glm::vec2 FindFurthestPoint(glm::vec2);
    glm::vec2 furthestPoint = glm::vec2(0,0);
};
