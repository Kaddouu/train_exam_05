#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget{
public:
	Dummy() : ATarget("Target Practice Dummy"){};
	Dummy(Dummy const &other){
		this->type = other.type;
	}
	Dummy& operator=(Dummy const &other){
		if (this != &other)
			this->type = other.type;
		return (*this);
	}
	Dummy* clone() const;
	~Dummy(){};
};