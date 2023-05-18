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

void Team::setNewLeader(){
    // Getting the last alive character location in the vector.
    Point closest(0,0);
    for(Character* character : team){
        if(character->isAlive()){
            closest = this->team.back()->getLocation();
            break;
        }
    }
    Character* new_leader;
    // Searching for a new leader.
    for(Character* character : team){
        if(character->isAlive()){
            if(this->leader->distance(character) < this->leader->getLocation().distance(closest)){
                new_leader = character;
            }
        }
    }

    this->leader = new_leader;
}

Character* Team::closestEnemy(Team* enemy_team){
    // Getting the last alive enemy character location in the enemy_team vector.
    Point closest(0,0);
    for(Character* character : team){
        if(character->isAlive()){
            closest = enemy_team->team.back()->getLocation();
            break;
        }
    }
    Character* closest_enemy;
    // Searching for the closest enemy.
    for(Character* character : enemy_team->team){
        if(character->isAlive()){
            if(this->leader->distance(character) < this->leader->getLocation().distance(closest)){
                closest_enemy = character;
            }
        }
    }

    return closest_enemy;
}

void Team::attack(Team* enemy_team){
    if(enemy_team == nullptr) {throw invalid_argument("Cannot give nullptr to the attack() method."); }

    if(!this->leader->isAlive()){
        this->setNewLeader();
    }

    Character* closest_enemy = this->closestEnemy(enemy_team);
    while(true){
        // Cowboy.
        for(Character* character : team){
            if(typeid(*character) == typeid(Cowboy)){
                Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
                if(closest_enemy->isAlive()){
                    cowboy->shoot(closest_enemy);
                } else{
                    closest_enemy = this->closestEnemy(enemy_team);
                }
            }
        }

        // Ninja.
        for(Character* character : team){
            if(typeid(*character) == typeid(Ninja)){
                Ninja* ninja = dynamic_cast<Ninja*>(character);
                if(closest_enemy->isAlive()){
                    ninja->slash(closest_enemy);
                } else{
                    closest_enemy = this->closestEnemy(enemy_team);
                }
            }

            if(!this->stillAlive() || !enemy_team->stillAlive()){
                return;
            }
        }
    }
}

int Team::stillAlive(){
    int alive = 0;
    for(Character* character : team){
        if(character->isAlive()){
            alive++;
        }
    }
    return alive;
}

void Team::print(){
    for(Character* character : team){
        cout << character->print() << endl;
    }
}

Team::~Team(){
    for (Character* character : team) {
        character->~Character();
    }
    // Clear the team vector
    team.clear();
}

