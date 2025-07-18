#pragma once
#include "ASpell.hpp"

class Polymorph : public ASpell{
	public:
		Polymorph() : ASpell("Polymorph", "turned into a critter"){};
		Polymorph(Polymorph const &other){
			this->name = other.name;
			this->effects = other.effects;
		}
		Polymorph& operator=(Polymorph const &other){
			if (this != &other)
			{
				this->name = other.name;
				this->effects = other.effects;
			}
			return (*this);
		}
		Polymorph* clone() const;
		~Polymorph(){};
};