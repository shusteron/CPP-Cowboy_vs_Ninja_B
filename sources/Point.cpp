#include "Point.hpp"
#include <ostream>
#include <iostream>
#include <cmath>

namespace ariel{}
using namespace std;


Point::Point(double x, double y){
    this->_x_ = x;
    this->_y_ = y;
}

double Point::distance(Point point){
    return sqrt(pow(this->getX() - point.getX(), 2) + pow(this->getY() - point.getY(), 2));
}

void Point::print(){
    cout << "(" + to_string(this->_x_) + "," + to_string(this->_y_) + ")"<<endl;
}

Point Point::moveTowards(Point from, Point goal, double distance){
    if(distance < 0){
        throw invalid_argument("Distance cannot be a negative number");
    }

    double current_distance = from.distance(goal);
    if(current_distance >= distance){
        return goal;
    } else {
        return Point((from.getX() + (distance * (goal.getX() - from.getX()) / current_distance)), 
                    (from.getY() + (distance * (goal.getY() - from.getY())/ current_distance)));
    }

}

double Point::getX(){
    return this->_x_;
}

double Point::getY(){
    return this->_y_;
}