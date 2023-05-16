#ifndef TEAM_HPP
#define TEAM_HPP
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>


namespace ariel{}

class Team{
    private:
        vector<Character*> team;
        Character* leader;

    public:
        Team(Character* leader);
        void add(Character* character);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();   
        ~Team();
};
#endif