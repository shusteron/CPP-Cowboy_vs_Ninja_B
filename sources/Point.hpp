#ifndef POINT_HPP
#define POINT_HPP

#include <stdio.h>
#include <string>

namespace ariel{}
using namespace std;

class Point{
    private:
        double _x_;
        double _y_;

    public:
        Point(double _x_, double _y_);   
        double distance(Point point);
        string print(); 
        static Point moveTowards(Point from, Point goal, double distance);
        double getX();
        double getY();
        void setX(double _x_);
        void setY(double _y_);
};

#endif
