#include "Warlock.hpp"

const std::string& Warlock::getName() const{
    return (this->name);
};
const std::string& Warlock::getTitle() const{
    return(this->title);
};
void Warlock::setTitle(const std::string &new_title){
    this->title = new_title;
};
void Warlock::introduce() const{
    std::cout << name + ": I am " + name + ", " + title + "!" << std::endl;
};

void Warlock::learnSpell(ASpell* spell){
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell){
	spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, ATarget &target){
	ASpell* spellToLaunch = spellBook.createSpell(spell);
	if (spellToLaunch) {
		spellToLaunch->launch(target);
		delete spellToLaunch;
	}
}
