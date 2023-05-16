#include "OldNinja.hpp"
#include <stdio.h>
#include <iostream>

#define OLD_HP 150
#define OLD_SPEED 8

namespace ariel{}
using namespace std;


OldNinja::OldNinja(string name, Point location):Ninja(name,location, OLD_HP, OLD_SPEED){

}

