#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
    std::string name;
    std::string title;
    std::vector<ASpell*> inventory;
    Warlock(const Warlock &other);
    Warlock &operator=(const Warlock &other);

public:
    Warlock(std::string name, std::string title) : name(name), title(title)
    {
        std::cout << name + ": This looks like another boring day" << std::endl;
    };
    ~Warlock()
    {
        for (int i = 0; i < (int)inventory.size(); ++i) {
            delete inventory[i];
        }
        std::cout << name + ": My job here is done!" << std::endl;
    };
    const std::string &getName() const;
    const std::string &getTitle() const;
    void setTitle(const std::string& new_title);
    void introduce() const;
	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spell);
	void launchSpell(std::string spell, ATarget &target);
};