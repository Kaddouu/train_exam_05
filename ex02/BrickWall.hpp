#pragma once
#include "ATarget.hpp"

class BrickWall : public ATarget{
private:
	BrickWall(BrickWall const &other);
	BrickWall& operator=(BrickWall const &other);
public:
	BrickWall();
	virtual BrickWall* clone() const;
	~BrickWall();
};