#include "SmartTeam.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

void SmartTeam::attack(Team* enemy_team){}