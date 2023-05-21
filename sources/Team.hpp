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
        virtual void attack(Team* enemy_team);
        int stillAlive();
        virtual void print();   
        void setNewLeader();
        Character* closestEnemy(Team* enemy_team);
        vector<Character*> getTeam() { return this->team; }
        Character* getLeader() { return this->leader; }
        void setLeader(Character* leader)  {this->leader = leader; }
        // To pass tidy:

        // Destructor.
        virtual ~Team();
        // Copy constuctor.
        Team(Team& other);
        // Copy assigment opertor ( = ).
        Team& operator=(const Team& other);
        // Move operator.
        Team& operator=(Team&& other) noexcept;
        // Move
        Team(Team&& other) noexcept;
};
#endif