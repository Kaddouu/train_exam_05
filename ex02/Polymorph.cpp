#include "Polymorph.hpp"

Polymorph* Polymorph::clone() const{
	return (new Polymorph(*this));
}