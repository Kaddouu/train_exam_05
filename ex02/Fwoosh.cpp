#include "Fwoosh.hpp"

Fwoosh* Fwoosh::clone() const{
	return (new Fwoosh(*this));
}