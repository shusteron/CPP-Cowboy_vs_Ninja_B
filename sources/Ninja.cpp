#include "Ninja.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;


Ninja::Ninja(string name, Point location, int hps, int speed):Character(name,location, hps), speed(speed){

}

void Ninja::move(Character* enemy){

}

void Ninja::slash(Character* enemy){
    
}

string Ninja::print(){
    return "";
}
