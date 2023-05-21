#include "Team2.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Team2::Team2(Character* leader) : Team(leader) {}

void Team2::attack(Team* enemy_team){
    if(enemy_team == nullptr) {throw invalid_argument("Cannot give nullptr to the attack() method."); }
    if(this->stillAlive() == 0 || enemy_team->stillAlive() == 0){ throw runtime_error("there is no characters to attack or attack with."); }

    // If the leader is dead, set a new one.
    if(!this->getLeader()->isAlive()){
        this->setNewLeader();
    }

    // If there is still characters alive in the enemy team, get the closest enemy.
    Character* closest_enemy = nullptr;
    if(enemy_team->stillAlive() > 0){
        closest_enemy = this->closestEnemy(enemy_team);
    } else {
        return;
    }

    for(auto& character : this->getTeam()) {
        if(character->isAlive()){
            if(dynamic_cast<Cowboy*>(character)) {
                Cowboy* cowboy =  (Cowboy*)(character);

                if (closest_enemy != nullptr) { // Check if closest_enemy is not nullptr
                    if (cowboy->isAlive()) {
                        if (closest_enemy->isAlive()) {
                            if (cowboy->hasBoolets()) {
                                cowboy->shoot(closest_enemy);
                            } else {
                                cowboy->reload();
                            }
                        }
                        if (!closest_enemy->isAlive() && enemy_team->stillAlive() > 0) {
                            closest_enemy = this->closestEnemy(enemy_team);

                        }
                    }
                }
            } else {
                Ninja* ninja = (Ninja*)(character);
                
                if (closest_enemy != nullptr) { // Check if closest_enemy is not nullptr
                    if (ninja->isAlive()) {
                        if (closest_enemy->isAlive()) {
                            if (ninja->distance(closest_enemy) <= 1) {
                                ninja->slash(closest_enemy);
                            } else {
                                ninja->move(closest_enemy);
                            }
                        }
                        if (!closest_enemy->isAlive() && enemy_team->stillAlive() > 0) {
                            closest_enemy = this->closestEnemy(enemy_team);
                        }
                    }
                }
            }
        }
    }
}

void Team2::print(){
    for(Character* character : this->getTeam()){
        cout << character->print() << endl;
    }
}