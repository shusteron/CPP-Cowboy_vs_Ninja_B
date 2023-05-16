#ifndef POINT_HPP
#define POINT_HPP

#include <stdio.h>

namespace ariel{}

class Point{
    private:
        double _x_;
        double _y_;

    public:
        Point(double _x_, double _y_);   
        double distance(Point point);
        void print(); 
        static Point moveTowards(Point from, Point goal, double distance);
        double getX();
        double getY();
};

#endif
