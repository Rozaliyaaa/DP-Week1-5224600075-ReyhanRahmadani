#include "RandomInputGenerator.h"

RandomInputGenerator::RandomInputGenerator()
    : engine(std::random_device{}()), dist(1,10) {}

TurnInput RandomInputGenerator::generate() {
    return TurnInput{dist(engine)};
}