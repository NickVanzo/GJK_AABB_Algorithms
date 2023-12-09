//
// Created by Nicolò Vanzo on 04/12/23.
//
#include "gtest/gtest.h"
#include "../classes/GJK.h"
TEST(GJKTest, CollisionDetected) {
    auto gjk = std::make_shared<GJK>();
    auto fish = std::make_shared<FishColliderComponent>();
    auto fish2 = std::make_shared<FishColliderComponent>();

    auto vertex1 = glm::vec2(1,-1);
    auto vertex2 = glm::vec2(1,1);
    auto vertex3 = glm::vec2(-1.5,1);
    auto vertex4 = glm::vec2(-1.5,-1);
    auto vertex5 = glm::vec2(-2.0,0);
    std::list<glm::vec2> vertexes = {};
    vertexes.push_back(vertex1);
    vertexes.push_back(vertex2);
    vertexes.push_back(vertex3);
    vertexes.push_back(vertex4);
    vertexes.push_back(vertex5);
    fish->vertexes = vertexes;

    vertexes.clear();
    vertexes.push_back(glm::vec2(2,1));
    vertexes.push_back(glm::vec2(2,2));
    vertexes.push_back(glm::vec2(0,0));
    vertexes.push_back(glm::vec2(5,2));
    vertexes.push_back(glm::vec2(5,0));

    fish2->vertexes = vertexes;

    EXPECT_TRUE(gjk->CheckGJKCollision(fish, fish2));
}
TEST(GJKTest, CollisionNotDetected) {
    auto gjk = std::make_shared<GJK>();
    auto fish = std::make_shared<FishColliderComponent>();
    auto fish2 = std::make_shared<FishColliderComponent>();

    auto vertex1 = glm::vec2(1,-1);
    auto vertex2 = glm::vec2(1,1);
    auto vertex3 = glm::vec2(-1.5,1);
    auto vertex4 = glm::vec2(-1.5,-1);
    auto vertex5 = glm::vec2(-2.0,0);
    std::list<glm::vec2> vertexes = {};
    vertexes.push_back(vertex1);
    vertexes.push_back(vertex2);
    vertexes.push_back(vertex3);
    vertexes.push_back(vertex4);
    vertexes.push_back(vertex5);
    fish->vertexes = vertexes;

    vertexes.clear();

    auto vertex11 = glm::vec2(100,10);
    auto vertex21 = glm::vec2(110,20);
    auto vertex32 = glm::vec2(110,0);
    auto vertex42 = glm::vec2(120,20);
    auto vertex52 = glm::vec2(120,0);

    vertexes.push_back(vertex11);
    vertexes.push_back(vertex21);
    vertexes.push_back(vertex32);
    vertexes.push_back(vertex42);
    vertexes.push_back(vertex52);

    fish2->vertexes = vertexes;
    EXPECT_FALSE( gjk->CheckGJKCollision(fish, fish2));
}
TEST(GJKTest, CollisionNotDetected2) {
    auto gjk = std::make_shared<GJK>();
    auto fish = std::make_shared<FishColliderComponent>();
    auto fish2 = std::make_shared<FishColliderComponent>();

    auto vertex1 = glm::vec2(1,-1);
    auto vertex2 = glm::vec2(1,1);
    auto vertex3 = glm::vec2(-1.5,1);
    auto vertex4 = glm::vec2(-1.5,-1);
    auto vertex5 = glm::vec2(-2.0,0);
    std::list<glm::vec2> vertexes = {};
    vertexes.push_back(vertex1);
    vertexes.push_back(vertex2);
    vertexes.push_back(vertex3);
    vertexes.push_back(vertex4);
    vertexes.push_back(vertex5);
    fish->vertexes = vertexes;

    vertexes.clear();

    auto vertex11 = glm::vec2(2,3);
    auto vertex21 = glm::vec2(3,4);
    auto vertex32 = glm::vec2(3,2);
    auto vertex42 = glm::vec2(4,4);
    auto vertex52 = glm::vec2(4,2);

    vertexes.push_back(vertex11);
    vertexes.push_back(vertex21);
    vertexes.push_back(vertex32);
    vertexes.push_back(vertex42);
    vertexes.push_back(vertex52);

    fish2->vertexes = vertexes;
    EXPECT_FALSE( gjk->CheckGJKCollision(fish, fish2));
}
TEST(GJKTest, CollisionDetectedWithNegativeCoordinates) {
    auto gjk = std::make_shared<GJK>();
    auto fish = std::make_shared<FishColliderComponent>();
    auto fish2 = std::make_shared<FishColliderComponent>();

    auto vertex1 = glm::vec2(-1,-1);
    auto vertex2 = glm::vec2(-1,-2);
    auto vertex3 = glm::vec2(-4,-1);
    auto vertex4 = glm::vec2(-4,-2);
    auto vertex5 = glm::vec2(-6,-1.5);
    std::list<glm::vec2> vertexes = {};
    vertexes.push_back(vertex1);
    vertexes.push_back(vertex2);
    vertexes.push_back(vertex3);
    vertexes.push_back(vertex4);
    vertexes.push_back(vertex5);
    fish->vertexes = vertexes;

    vertexes.clear();

    auto vertex11 = glm::vec2(-3,-3);
    auto vertex21 = glm::vec2(-4,-2);
    auto vertex32 = glm::vec2(-2,-2);
    auto vertex42 = glm::vec2(-4,-1);
    auto vertex52 = glm::vec2(-2,-1);

    vertexes.push_back(vertex11);
    vertexes.push_back(vertex21);
    vertexes.push_back(vertex32);
    vertexes.push_back(vertex42);
    vertexes.push_back(vertex52);

    fish2->vertexes = vertexes;
    EXPECT_TRUE( gjk->CheckGJKCollision(fish, fish2));
}
/**
 *          [1,1]  [2,1]
 *    [0,0]              [4,0]
 *          [1,-1] [2,-1]
 *
 *         [3,1]   [4,1]
 *    [2,0]              [6,0]
 *          [3,-1] [4,-1]
 */
TEST(GJKTest, CollisionDetectedWithExagon) {
    auto gjk = std::make_shared<GJK>();
    auto fish = std::make_shared<FishColliderComponent>();
    auto fish2 = std::make_shared<FishColliderComponent>();

    auto vertex1 = glm::vec2(0,0);
    auto vertex2 = glm::vec2(1,1);
    auto vertex3 = glm::vec2(2,1);
    auto vertex6 = glm::vec2(4,0);
    auto vertex5 = glm::vec2(2,-1);
    auto vertex4 = glm::vec2(1,-1);

    std::list<glm::vec2> vertexes = {};
    vertexes.push_back(vertex1);
    vertexes.push_back(vertex2);
    vertexes.push_back(vertex3);
    vertexes.push_back(vertex6);
    vertexes.push_back(vertex5);
    vertexes.push_back(vertex4);

    fish->vertexes = vertexes;

    vertexes.clear();

    auto vertex11 = glm::vec2(2,0);
    auto vertex21 = glm::vec2(3,1);
    auto vertex42 = glm::vec2(4,1);
    auto vertex62 = glm::vec2(6,0);
    auto vertex52 = glm::vec2(4,-1);
    auto vertex32 = glm::vec2(3,-1);

    vertexes.push_back(vertex11);
    vertexes.push_back(vertex21);
    vertexes.push_back(vertex62);
    vertexes.push_back(vertex42);
    vertexes.push_back(vertex52);
    vertexes.push_back(vertex32);

    fish2->vertexes = vertexes;
    EXPECT_TRUE( gjk->CheckGJKCollision(fish, fish2));
}