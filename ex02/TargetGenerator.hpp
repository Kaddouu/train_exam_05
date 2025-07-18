#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
private:
    std::vector<ATarget*> targets;
    TargetGenerator(const TargetGenerator &other);
    TargetGenerator &operator=(const TargetGenerator &other);

public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const &targetName);
    ATarget* createTarget(std::string const &targetName);
};