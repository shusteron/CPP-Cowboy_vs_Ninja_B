#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}


class Cowboy:  public Character{
    private:
        int bullets;

    public:
        Cowboy(string name, Point location);
        void shoot(Character* enemy);
        bool hasBoolets();
        void reload();
        string print() override;


};
#endif