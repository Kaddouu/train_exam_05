#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell{
	public:
		Fwoosh() : ASpell("Fwoosh", "fwooshed"){};
		Fwoosh(Fwoosh const &other){
			this->name = other.name;
			this->effects = other.effects;
		}
		Fwoosh& operator=(Fwoosh const &other){
			if (this != &other)
			{
				this->name = other.name;
				this->effects = other.effects;
			}
			return (*this);
		}
		Fwoosh* clone() const;
		~Fwoosh(){};
};