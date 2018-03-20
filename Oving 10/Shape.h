//
// Created by Nicolai Stølen on 20/03/2018.
//

#ifndef TDT4102_SHAPE_H
#define TDT4102_SHAPE_H



#include "Image.h"

struct Point {
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {};

    Point operator-(Point rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
};

class Shape {
    Color color;

public:
    explicit Shape(Color color): color(color) {};

    Color getColor() const;

    virtual void draw(Image& im)= 0;
};

#endif //TDT4102_SHAPE_H