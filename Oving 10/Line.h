//
// Created by Nicolai Stølen on 20/03/2018.
//

#include "Shape.h"

#ifndef TDT4102_LINE_H
#define TDT4102_LINE_H




class Line: public Shape {
    Point start;
    Point end;
    Point diff;
public:
    Line(Color color, Point start, Point end);

    void draw(Image &im) override;

    Point getStart();
    Point getEnd();
};

#endif //TDT4102_LINE_H