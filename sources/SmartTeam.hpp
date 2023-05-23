#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <stdio.h>
#include <iostream>
#include "Team.hpp"

namespace ariel{}

class SmartTeam: public Team{    
    public:
        SmartTeam(Character* leader);
        void attack(Team* enemy_team) override;
        Character* farthestCharacter(Character* curr, Team* team);
};


#endif