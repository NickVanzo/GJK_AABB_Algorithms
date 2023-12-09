//
// Created by Nicolò Vanzo on 04/12/23.
//

#include "FishColliderComponent.h"
#include <iostream>

glm::vec2 FishColliderComponent::FindFurthestPoint(glm::vec2 dir) {
    glm::vec2 maxPoint = glm::vec2(0,0);
    float maxDistance = -999999;

    for(auto it = vertexes.begin(); it != vertexes.end(); ++it) {
        const auto& vertex = *it;
        /**
         * The vertex with the highest projection is considered the furthest point in the specified direction.
         */
        float distance = vertex.x * dir.x + vertex.y * dir.y;
        if(distance > maxDistance) {
            maxDistance = distance;
            maxPoint = glm::vec2(vertex.x, vertex.y);
        }
    }
    return maxPoint;
}

