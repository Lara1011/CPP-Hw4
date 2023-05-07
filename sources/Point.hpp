//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef CPP_HW4_POINT_H
#define CPP_HW4_POINT_H
using namespace ariel;

class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double num1, double num2);
    double distance(Point other);
    void moveTowards(Point source, Point destination, double distance);
    void print();
};


#endif //CPP_HW4_POINT_H