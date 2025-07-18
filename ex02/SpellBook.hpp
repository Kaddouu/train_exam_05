#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"

class SpellBook {
private:
	std::vector<ASpell*> spells;
	SpellBook(SpellBook const &other);
	SpellBook& operator=(SpellBook const &other);

public:
	SpellBook();
	~SpellBook();
	
	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const &spellName);
	ASpell* createSpell(std::string const &spellName);
};