#include "ATarget.hpp"

const std::string& ATarget::getType() const{
	return this->type;
}

void ATarget::getHitBySpell(ASpell const &spell) const{
	std::cout << type + " has been " + spell.getEffects() + "!" << std::endl;
}

ATarget& ATarget::operator=(ATarget const &other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
ATarget::ATarget(ATarget const &other) : type(other.type) {}