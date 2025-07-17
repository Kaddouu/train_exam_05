#pragma once
#include <string>
#include <iostream>

class ASpell
{
private:
    std::string name;
    std::string effects;

public:
    ASpell(std::string name, std::string effects) : name(name), effects(effects){}
    const std::string &getName() const;
    const std::string &getEffects() const;
    virtual ASpell *clone() const = 0;
};