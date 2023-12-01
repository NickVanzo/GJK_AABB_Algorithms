#include <iostream>
#include "string"
#include "classes/AABB.h"

int main() {
        auto aabb = std::make_shared<ConcreteStrategyAABB::AABB>();
        auto bc1 = std::make_shared<Component>();
        auto bc2 = std::make_shared<Component>();
    bool collisionDetected = aabb->checkCollision(bc1, bc2);
    std::cout << "collision detected " << collisionDetected << std::endl;
    return 0;
}
