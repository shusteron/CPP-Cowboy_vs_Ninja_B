#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdio.h>
#include <iostream>
#include "Point.hpp"

namespace ariel{}
using namespace std;

class Character{
    private:
        Point location;
        int hps; 
        string name;
        bool team_flag = false;

    public:
        Character(string name, Point location, int hps);
        Character(string name, Point location);
        bool isAlive();
        double distance(Character* other_character);
        void hit(int dmg);
        string getName();
        Point getLocation();
        void setLocation(Point location);
        virtual string print() = 0;   
        int getHP();
        bool hasTeam();
        void setHasTeam(bool flag);
        // To pass tidy:

        // Destructor.
        virtual ~Character() = default;
        // Copy constuctor.
        Character(const Character& other);
        // Copy assigment opertor ( = ).
        Character& operator=(const Character& other);
        // Move operator
        Character& operator=(Character&& other) noexcept;
        // Move
        Character(Character&& other) noexcept;

};
#endif