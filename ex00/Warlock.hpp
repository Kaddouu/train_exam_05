#pragma once
#include <string>
#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock(const Warlock &other);
    Warlock &operator=(const Warlock &other);

public:
    Warlock(std::string name, std::string title) : name(name), title(title)
    {
        std::cout << name + ": This looks like another boring day" << std::endl;
    };
    virtual ~Warlock()
    {
        std::cout << name + ": My job here is done!" << std::endl;
    };
    const std::string &getName() const;
    const std::string &getTitle() const;
    void setTitle(const std::string& new_title);
    void introduce() const;
};