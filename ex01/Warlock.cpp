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
	if (spell)
	{
        for (int i = 0; i < (int)inventory.size(); ++i)
		{
			if (inventory[i]->getName() == spell->getName())
				return;
		}
		inventory.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(std::string spell){
	for (int i = 0; i < (int)inventory.size(); ++i)
	{
		if (inventory[i]->getName() == spell)
		{
			delete inventory[i];
			inventory.erase(inventory.begin() + i);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spell, ATarget &target){
	for(int i = 0; i < (int)inventory.size(); ++i)
	{
		if (inventory[i]->getName() == spell)
		{
			inventory[i]->launch(target);
			return ;
		}
	}
}
