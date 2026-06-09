#include "StaticBody.h"

StaticBody::StaticBody() = default;

StaticBody::StaticBody(int transform_index) {
    this->transform_index = transform_index;
}