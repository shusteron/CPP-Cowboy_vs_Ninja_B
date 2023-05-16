#include "TrainedNinja.hpp"
#include <stdio.h>
#include <iostream>

#define TRAINED_HP 120
#define TRAINED_SPEED 12

namespace ariel{}
using namespace std;

TrainedNinja::TrainedNinja(string name, Point location):Ninja(name,location, TRAINED_HP, TRAINED_SPEED){

}