#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (size_t i = 0; i < targets.size(); ++i) {
        delete targets[i];
    }
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target) {
        for (size_t i = 0; i < targets.size(); ++i) {
            if (targets[i]->getType() == target->getType()) {
                return;
            }
        }
        targets.push_back(target->clone());
    }
}

void TargetGenerator::forgetTargetType(std::string const &targetName) {
    for (size_t i = 0; i < targets.size(); ++i) {
        if (targets[i]->getType() == targetName) {
            delete targets[i];
            targets.erase(targets.begin() + i);
            return;
        }
    }
}

ATarget* TargetGenerator::createTarget(std::string const &targetName) {
    for (size_t i = 0; i < targets.size(); ++i) {
        if (targets[i]->getType() == targetName) {
            return targets[i]->clone();
        }
    }
    return NULL;
}
