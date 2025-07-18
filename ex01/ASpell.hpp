#pragma once
#include <string>
#include <iostream>

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;
	ASpell(ASpell const &other);
	ASpell& operator=(ASpell const &other);

public:
	ASpell(){};
	ASpell(std::string name, std::string effects) : name(name), effects(effects){};
	virtual ~ASpell(){};
	const std::string &getName() const;
    const std::string &getEffects() const;
	void launch(ATarget const& target) const;

    virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"