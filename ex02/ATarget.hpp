#pragma once
#include <string>
#include <iostream>

class ASpell;

class ATarget {
	protected:
	std::string type;
	private:
	
	public:
		ATarget& operator=(ATarget const &other);
		ATarget(ATarget const &other);
		ATarget(){};
		ATarget(std::string type) : type(type) {};
		const std::string& getType() const;
		void getHitBySpell(ASpell const &spell) const;
		virtual ATarget* clone() const = 0;
		virtual ~ATarget(){};
};

#include "ASpell.hpp"