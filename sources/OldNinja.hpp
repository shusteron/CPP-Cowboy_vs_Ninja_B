#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
#include <stdio.h>

namespace ariel{}

class OldNinja: public Ninja{
    private:

    public:
        OldNinja(string name, Point location);
};
#endif