#include "Fireball.hpp"

Fireball* Fireball::clone() const{
	return (new Fireball(*this));
}