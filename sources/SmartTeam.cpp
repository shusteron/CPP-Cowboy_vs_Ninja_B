#include "SmartTeam.hpp"
#include <stdio.h>
#include <iostream>
#include <limits>


namespace ariel{}
using namespace std;

SmartTeam::SmartTeam(Character* leader) : Team(leader) {}


// A help function to find the farthest character from the given in the function.
Character* SmartTeam::farthestCharacter(Character* curr, Team* team){
    double max_dis = numeric_limits<double>::min();
    Character* farthest = nullptr;

    // Searching for the farthest alive character.
    for(Character* character : team->getTeam()){
        if(character->isAlive()){
            if(curr->distance(character) > max_dis){
                max_dis = curr->distance(character);
                farthest = character;
            }
        }
    }
    return farthest;
}

/*
    Here the algorithem idea is:
    - The SmartTeam cowboys will attack the farthest character in the enemy team.
*/
void SmartTeam::attack(Team* enemy_team){

    if(enemy_team == nullptr) {throw invalid_argument("Cannot give nullptr to the attack() method."); }
    if(this->stillAlive() == 0 || enemy_team->stillAlive() == 0){ throw runtime_error("there is no characters to attack or attack with."); }

    // If the leader is dead, set a new one.
    if(!this->getLeader()->isAlive()){
        this->setNewLeader();
    }

    // If there is still characters alive in the enemy team, get the closest enemy.
    Character* closest_enemy = nullptr;
    closest_enemy = this->closestEnemy(enemy_team);


    Character* farthest = nullptr;
    for(auto& character : this->getTeam()){
        if(dynamic_cast<Cowboy*>(character) && character->isAlive()) {
            Cowboy* cowboy =  (Cowboy*)(character);
            farthest = this->farthestCharacter(cowboy,enemy_team);
            break;
        }
    }



    for(auto& character: this->getTeam()){
        if(character->isAlive()){

            if(dynamic_cast<Cowboy*>(character)) {
                // Cowboy.
                Cowboy* cowboy =  (Cowboy*)(character);
                if(farthest != nullptr){
                    if(cowboy->isAlive()){
                        if(farthest->isAlive()){
                            if (cowboy->hasBoolets()) { //If the target is alive and you have bullets -> shoot him, else, reload.
                                cowboy->shoot(farthest);
                            } else {
                                cowboy->reload();
                            }
                        }
                        if (!farthest->isAlive() && enemy_team->stillAlive() > 0) {    //If the target is dead, find a new one.
                            farthest = this->farthestCharacter(cowboy, enemy_team);
                        } 
                    }
                }
            } 

            // Ninja.
            else {
                Ninja* ninja = (Ninja*)(character);
                
                if (closest_enemy != nullptr) { 
                    if (ninja->isAlive()) {
                        if (closest_enemy->isAlive()) {
                            if (ninja->distance(closest_enemy) <= 1) {  //If the target is alive and you are close enough to attack -> slash him, else, get closer to the target.
                                ninja->slash(closest_enemy);
                            }
                            else {
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