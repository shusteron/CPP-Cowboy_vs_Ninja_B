#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <stdio.h>
#include <iostream>
#include "Team.hpp"

namespace ariel{}

class Team2: public Team{
    
    public:
        Team2(Character* leader);
        void attack(Team* enemy_team) override;
        void print() override;

};


#endif