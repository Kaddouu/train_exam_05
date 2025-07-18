#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (int i = 0; i < (int)spells.size(); ++i) {
		delete spells[i];
	}
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		for (int i = 0; i < (int)spells.size(); ++i) {
			if (spells[i]->getName() == spell->getName()) {
				return;
			}
		}
		spells.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(std::string const &spellName) {
	for (int i = 0; i < (int)spells.size(); ++i) {
		if (spells[i]->getName() == spellName) {
			delete spells[i];
			spells.erase(spells.begin() + i);
			return;
		}
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	for (int i = 0; i < (int)spells.size(); ++i) {
		if (spells[i]->getName() == spellName) {
			return spells[i]->clone();
		}
	}
	return NULL;
}
