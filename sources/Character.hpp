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
        virtual string print() = 0;   
        bool isHasTeam();
        void setHasTeam(bool flag);
        virtual ~Character() = default;

};
#endif