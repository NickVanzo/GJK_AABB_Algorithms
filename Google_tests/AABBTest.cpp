#include "gtest/gtest.h"
#include "../classes/AABB.h"

TEST(TwoShapesCollide, FirstTest) {
    auto aabb = std::make_shared<ConcreteStrategyAABB::AABB>();
    auto bc1 = std::make_shared<Component>();
    auto bc2 = std::make_shared<Component>();
    EXPECT_EQ(aabb->checkCollision(bc1, bc2), true);
}
TEST(TwoShapesDoNotCollide, FirstTest) {
    auto aabb = std::make_shared<ConcreteStrategyAABB::AABB>();
    auto bc1 = std::make_shared<Component>();
    auto bc3 = std::make_shared<Component>();
    bc3->center = glm::vec2(100,100);
    EXPECT_EQ(aabb->checkCollision(bc1, bc3), false);
}

