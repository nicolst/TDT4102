//
// Created by Nicolai Stølen on 20/03/2018.
//

#ifndef TDT4102_RECTANGLE_H
#define TDT4102_RECTANGLE_H



#include "Line.h"

class Rectangle: public Shape {
    Line diagonal;

public:
    explicit Rectangle(Line diagonal);

    void draw(Image& im) override;
};

#endif //TDT4102_RECTANGLE_H