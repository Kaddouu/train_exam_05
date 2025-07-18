#include "ASpell.hpp"
#include "ATarget.hpp"

const std::string& ASpell::getName() const{
	return (this->name);
}
const std::string& ASpell::getEffects() const{
	return this->effects;
}

void ASpell::launch(ATarget const& target) const{
	target.getHitBySpell(*this);
}



