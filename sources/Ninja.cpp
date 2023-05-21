#include "Ninja.hpp"
#include <stdio.h>
#include <iostream>

#define ATTACK_DMG 40

namespace ariel{}
using namespace std;


Ninja::Ninja(string name, Point location, int hps, int speed):Character(name,location, hps), speed(speed) {}

// Moves ninja to a new location.
void Ninja::move(Character* enemy){
    double distance = this->distance(enemy);

    // If the move speed in enough to reach the enemy location -> set the location to the enemy
    // Else, get closer to the enemy location.
    if(distance <= this->speed){
        this->setLocation(enemy->getLocation());
    } else {
        Point new_location = this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
        this->setLocation(new_location);
    }
}

void Ninja::slash(Character* enemy){
    // Dead enemy.
    if(enemy->isAlive() == false){ throw runtime_error("Cannot slash dead enemy."); }
    // Dead ninja trying to slash.
    if(!this->isAlive()){ throw runtime_error("Dead ninja cannot slash."); }
    // Trying to slash himself.
    if(enemy == this){ throw runtime_error("Ninja cnnot slash himself."); }

    if(this->distance(enemy) <= 1){
        enemy->hit(ATTACK_DMG);
    }
}

string Ninja::print(){
    if ( this->isAlive()){
        return "N name:" + this->getName() + " HP: " + to_string(this->getHP()) + "Location: " + this->getLocation().print();
    }
    return "N name:(" + this->getName() + ") " + " Location: " + this->getLocation().print();
}
