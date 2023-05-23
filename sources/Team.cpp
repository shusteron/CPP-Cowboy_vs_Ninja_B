#include "Team.hpp"
#include <stdio.h>
#include <iostream>
#include <limits>

namespace ariel{}
using namespace std;

#define MAX_TEAMATES 10

Team::Team(Character* leader): leader(leader){
    if(leader->hasTeam()){
        throw runtime_error("Leader is already signed to a team.");
    }
    this->team.push_back(leader);
    leader->setHasTeam(true);
}

// Adding a new character to the team.
void Team::add(Character* character){
    if(character->hasTeam()){ throw runtime_error("Character is already signed to a team"); }

    if(this->team.size() < MAX_TEAMATES && character->isAlive()){
        this->team.push_back(character);
        character->setHasTeam(true);
    } else {
        throw runtime_error("Tried to add more than 10 characters to team.");
    }
}

// Sets a new leader to the team.
void Team::setNewLeader(){
    double min_dis =numeric_limits<double>::max();
    Character* new_leader = nullptr;
    // Searching for a new leader.
    for(Character* character : this->getTeam()){
            if(character->isAlive() && this->getLeader()->distance(character) < min_dis){
                min_dis = this->getLeader()->distance(character);
                new_leader = character;
            }
    }
    setLeader(new_leader);
}

// Returns the closest enemy to the leader.
Character* Team::closestEnemy(Team* enemy_team){  
    double min_dis = numeric_limits<double>::max();
    Character* closest_enemy = nullptr;

    // Searching for the closest alive enemy.
    for(Character* character : enemy_team->getTeam()){
        if(character->isAlive()){
            if(this->getLeader()->distance(character) < min_dis){
                min_dis = this->getLeader()->distance(character);
                closest_enemy = character;
            }
        }
    }
    return closest_enemy;
}

void Team::attack(Team* enemy_team){
    if(enemy_team == nullptr) {throw invalid_argument("Cannot give nullptr to the attack() method."); }
    if(this->stillAlive() == 0 || enemy_team->stillAlive() == 0){ throw runtime_error("there is no characters to attack or attack with."); }

    // If the leader is dead, set a new one.
    if(!this->leader->isAlive()){
        this->setNewLeader();
    }

    // If there is still characters alive in the enemy team, get the closest enemy.
    Character* closest_enemy = nullptr;
    closest_enemy = this->closestEnemy(enemy_team);

    // Cowboy.
    for(auto& character : team) {
        if(character->isAlive()) {
            if(dynamic_cast<Cowboy*>(character)) {
                Cowboy* cowboy =  (Cowboy*)(character);
                if (closest_enemy != nullptr) {
                    if (cowboy->isAlive()) {
                        if (closest_enemy->isAlive()) { 
                            if (cowboy->hasBoolets()) { //If the target is alive and you have bullets -> shoot him, else, reload.
                                cowboy->shoot(closest_enemy);
                            } else {
                                cowboy->reload();
                            }
                        }
                        if (!closest_enemy->isAlive() && enemy_team->stillAlive() > 0) {    //If the target is dead, find a new one.
                            closest_enemy = this->closestEnemy(enemy_team);
                        } 
                    }
                }
            }
        }
    }

    // Ninja.
    for(auto& character : team) {
        if(character->isAlive()) {
            if(dynamic_cast<Ninja*>(character)) {
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

// A method thar returns how many alive in the team.
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
        if(dynamic_cast<Cowboy*>(character)){
            cout << character->print() << endl;
        }
    }
    for(Character* character : team){
        if(dynamic_cast<Ninja*>(character)){
            cout << character->print() << endl;
        }
    }
}

// To pass tidy methods:
Team::~Team(){
    for (Character* character : team) {
        delete character;
    }
    // Clear the team vector.
    team.clear();
}

// Copy constuctor.
Team::Team(Team& other){
    team = other.team;
    leader = other.leader;
}

// Copy assigment operator (=).
Team& Team::operator=(const Team& other){
    if(this == &other){
        return *this;
    }
    team = other.team;
    leader = other.leader;

    return *this;
}

//Move assigment operator (=).
Team& Team::operator=(Team&& other) noexcept{
    team = other.team;
    leader = other.leader;

    return *this;
}

// Move
Team::Team(Team&& other) noexcept{
    team = other.team;
    leader = other.leader;
}