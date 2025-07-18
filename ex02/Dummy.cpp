#include "Dummy.hpp"

Dummy* Dummy::clone() const{
	return (new Dummy(*this));
}