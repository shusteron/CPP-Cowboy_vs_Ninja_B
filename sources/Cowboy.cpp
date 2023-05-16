#include "Cowboy.hpp"
#include <stdio.h>
#include <iostream>

#define COWBOY_HP 110
#define BULLETS 6

namespace ariel{}
using namespace std;


Cowboy::Cowboy(string name, Point location): Character(name,location, COWBOY_HP), bullets(BULLETS){
    
}

void Cowboy::shoot(Character* enemy){

}

bool Cowboy::hasBoolets(){
    return false;
}

void Cowboy::reload(){

}

string Cowboy::print(){
    return "";
}