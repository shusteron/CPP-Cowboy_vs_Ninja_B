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

// Calculating distance between two points.
double Point::distance(Point point){
    return sqrt(pow(this->getX() - point.getX(), 2) + pow(this->getY() - point.getY(), 2));
}

string Point::print(){
    return "(" + to_string(this->_x_) + "," + to_string(this->_y_) + ")";
}

// Returns the closest point to goal considering the distance.
Point Point::moveTowards(Point from, Point goal, double distance){
    if(distance < 0){
        throw invalid_argument("Distance cannot be a negative number");
    }

    double current_distance = from.distance(goal);
    if(current_distance <= distance){
        return goal;
        
    } else {
        double ratio = distance / current_distance;
        double new_x = from.getX() + (ratio * (goal.getX() - from.getX()));
        double new_y = from.getY() + (ratio * (goal.getY() - from.getY()));
        return Point(new_x, new_y);
    }
}

double Point::getX() const{
    return this->_x_;
}

double Point::getY() const{
    return this->_y_;
}

void Point::setX(double x){
    this->_x_ = x;
}

void Point::setY(double y){
    this->_y_ = y;
}