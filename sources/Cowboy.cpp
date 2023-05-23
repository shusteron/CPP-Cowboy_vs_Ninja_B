#include "Cowboy.hpp"
#include <stdio.h>
#include <iostream>

#define COWBOY_HP 110
#define BULLETS 6
#define ATTACK_DMG 10

namespace ariel{}
using namespace std;


Cowboy::Cowboy(string name, Point location): Character(name,location, COWBOY_HP), bullets(BULLETS){
    
}

void Cowboy::shoot(Character* enemy){
    // Dead enemy.
    if(!enemy->isAlive()){ throw runtime_error("Cannot shoot dead enemy."); }
    // Dead cowboy trying to shoot.
    if(!this->isAlive()){ throw runtime_error("Dead Cowboy cannot shoot."); }
    // Trying to shoot himself.
    if(enemy == this){ throw runtime_error("Cowboy cannot shoot himself."); }

    // If cowboy has no bullets -> don't do anything.
    if(!this->hasBoolets()){
        return;
    }
    enemy->hit(ATTACK_DMG);
    this->bullets -= 1;
}

// Checks if the cowboy has bullets.
bool Cowboy::hasBoolets(){
    return this->bullets;
}


void Cowboy::reload(){
    if(!this->isAlive()) { throw runtime_error("Dead cowboy cannot reload."); }
    this->bullets = BULLETS;
}

string Cowboy::print(){
    if ( this->isAlive()){
        return "C  name:" + this->getName() + " HP: " + to_string(this->getHP()) + "Location: " + this->getLocation().print();
    }
    return "C  name:(" + this->getName() + ") " + " Location: " + this->getLocation().print();
}