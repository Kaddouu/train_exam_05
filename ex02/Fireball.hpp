#pragma once
#include "ASpell.hpp"

class Fireball : public ASpell{
	public:
		Fireball() : ASpell("Fireball", "burnt to a crisp"){};
		Fireball(Fireball const &other){
			this->name = other.name;
			this->effects = other.effects;
		}
		Fireball& operator=(Fireball const &other){
			if (this != &other)
			{
				this->name = other.name;
				this->effects = other.effects;
			}
			return (*this);
		}
		Fireball* clone() const;
		~Fireball(){};
};