#include "gtest/gtest.h"
#include "../classes/AABB.h"
#include "../classes/BoxColliderComponent.h"

TEST(TwoShapesCollide, FirstTest) {
    auto aabb = std::make_shared<ConcreteStrategyAABB::AABB>();
    auto bc1 = std::make_shared<BoxColliderComponent>();
    auto bc2 = std::make_shared<BoxColliderComponent>();
    bc1->setHorizontal(1);
    bc1->setVertical(1);
    bc2->setHorizontal(1);
    bc2->setVertical(1);
    EXPECT_TRUE(aabb->checkCollision(bc1, bc2));
}
TEST(TwoShapesDoNotCollide, FirstTest) {
    auto aabb = std::make_shared<ConcreteStrategyAABB::AABB>();
    auto bc1 = std::make_shared<Component>();
    auto bc3 = std::make_shared<Component>();
    bc3->center = glm::vec2(100,100);
    EXPECT_EQ(aabb->checkCollision(bc1, bc3), false);
}

