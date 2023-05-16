#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <stdio.h>
#include <iostream>
#include "Team.hpp"

namespace ariel{}

class Team2: public Team{
    // private:
    //     vector<Character*> team;
    //     Character* leader;

    public:
        Team2(Character* leader);
};


#endif