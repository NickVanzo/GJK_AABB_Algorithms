//
// Created by Nicolò Vanzo on 30/11/23.
//

#include "BoxColliderComponent.h"

int BoxColliderComponent::getHorizontalOffset() {
    return horizontalOffset;
}

int BoxColliderComponent::getVerticalOffset() {
    return verticalOffset;
}
void BoxColliderComponent::setHorizontal(int _v) {
    horizontalOffset = _v;
}
void BoxColliderComponent::setVertical(int _v) {
    verticalOffset = _v;
}
