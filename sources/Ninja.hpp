#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}

class Ninja: public Character{
    private:
        int speed;

    public:
        Ninja(string name, Point location, int hps, int speed);
        void move(Character* enemy);     
        void slash(Character* enemy);
        string print() override;
};
#endif
