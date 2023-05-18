#include "Team.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;


Team::Team(Character* leader): leader(leader){
    if(leader->hasTeam()){
        throw runtime_error("Leader is already signed to a team.");
    }
    this->team.push_back(leader);
    leader->setHasTeam(true);
}

void Team::add(Character* character){
    if(this->team.size() < 10){
        if(character->hasTeam()){ throw runtime_error("Character is already signed to a team"); }
        this->team.push_back(character);
        character->setHasTeam(true);
    } else {
        throw runtime_error("Tried to add more than 10 characters to team.");
    }
}

void Team::attack(Team* enemy_team){
    if(enemy_team == nullptr) {throw invalid_argument("Cannot give nullptr to the attack() method."); }


}

int Team::stillAlive(){
    int alive = 0;
    for(const auto& Character : team){
        if(Character->isAlive()){
            alive++;
        }
    }
    return alive;
}

void Team::print(){
    for(const auto& Character : team){
        cout << Character->print() << endl;
    }
}

Team::~Team(){
    for (Character* character : team) {
        delete character;
    }
    // Clear the team vector
    team.clear();
}