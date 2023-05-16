#include "Team.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;


Team::Team(Character* leader): leader(leader){
    this->team.push_back(leader);
}

void Team::add(Character* character){

}

void Team::attack(Team* enemy_team){

}

int Team::stillAlive(){
    return 0;
}

void Team::print(){

}

Team::~Team(){
    for (Character* character : team) {
        delete character;
    }
    // Clear the team vector
    team.clear();
}