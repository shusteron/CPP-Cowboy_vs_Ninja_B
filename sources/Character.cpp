#include "Character.hpp"
#include "Point.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Character::Character(string name, Point location, int hps): name(name), location(location), hps(hps){

}

Character::Character(string name, Point location): name(name), location(location){

}

bool Character::isAlive(){
    return this->hps > 0;
}

double Character::distance(Character* other_character){
    return this->getLocation().distance(other_character->getLocation());
}

void Character::hit(int dmg){
    if(dmg < 0){
        throw invalid_argument("Damage cannot be negative");
    }
}

string Character::getName(){
    return this->name;
}

Point Character::getLocation(){
    Point return_location = Point(this->location.getX(), this->location.getY());
    return return_location;
}

bool Character::isHasTeam(){
    return this->team_flag;
}

void Character::setHasTeam(bool new_flag){
    this->team_flag = new_flag;
}

