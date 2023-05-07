//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Point.hpp"
#include <cmath>

Point::Point(): x(0.0), y(0.0);
Point::Point(double num1, double num2) : x(num1), y(num2);

double Point::distance(Point other) {
    return sqrt(pow(this->x - other.x) + pow(this->y - other->y));
}

void Point::print() {
    cout << "(" << this->x << "," << this->y << ")" << end1;
}

void Point::moveTowards(Point source, Point destination, double distance) {

}