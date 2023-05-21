#include "Character.hpp"
#include "Point.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Character::Character(string name, Point location, int hps): name(name), location(location), hps(hps){}

Character::Character(string name, Point location): name(name), location(location){}

// Return if cahracter is alive.
bool Character::isAlive(){
    return this->hps > 0;
}

// Measure distance between two characters.
double Character::distance(Character* other_character){
    return this->getLocation().distance(other_character->getLocation());
}

// Sets new location.
void Character::setLocation(Point location){
    this->location.setX(location.getX());
    this->location.setY(location.getY());
}

// A method that reduce character's HP.
void Character::hit(int dmg){
    // Damage must be greater than zero.
    if(dmg < 0){
        throw invalid_argument("Damage cannot be negative");
    }
    if(this->hps - dmg >= 0)
        this->hps -= dmg;
    else
        this->hps=0;    
}

// Returns charactrer's name.
string Character::getName(){
    return this->name;
}

// Returns character's location point.
Point Character::getLocation() const{
    Point return_location = Point(this->location.getX(), this->location.getY());
    return return_location;
}

// Checks if the current character has team.
bool Character::hasTeam(){
    return this->team_flag;
}

// Updating character's team status.
void Character::setHasTeam(bool new_flag){
    this->team_flag = new_flag;
}

// Returns character's HP.
int Character::getHP(){
    return this->hps;
}


// To pass tidy methods:

// Copy constuctor.
Character :: Character(const Character& other) : name(other.name), location(other.location), hps(other.hps), team_flag(other.team_flag){}
   
// Copy assigment operator (=).
Character& Character::operator=(const Character& other){
    if(this == &other){
        return *this;
    }
    name = other.name;
    location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps= other.hps;
    team_flag = other.team_flag;

    return *this;
}

//Move assigment operator (=).
Character& Character :: operator=(Character&& other) noexcept{
    name = other.name;
    other.name = nullptr;
    location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps = other.hps;
    team_flag = other.team_flag;

    return *this;
}

// Move
Character:: Character(Character&& other) noexcept : location(other.location){
    name=other.name;
    other.name = nullptr;
    // location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps = other.hps;
    team_flag = other.team_flag;
}


