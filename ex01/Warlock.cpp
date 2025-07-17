#include "Warlock.hpp"

const std::string& Warlock::getName() const{
    return (this->name);
};
const std::string& Warlock::getTitle() const{
    return(this->title);
};
void Warlock::setTitle(const std::string &new_title){
    this->title = new_title;
};
void Warlock::introduce() const{
    std::cout << name + ": I am " + name + ", " + title + "!" << std::endl;
};
