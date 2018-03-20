//
// Created by Nicolai Stølen on 20/03/2018.
//

#include <vector>
#include "Shape.h"

#ifndef TDT4102_CANVAS_H
#define TDT4102_CANVAS_H



class Canvas {
    std::vector<Shape*> shapes;

public:
    void addShape(Shape* shape);
    void rasterizeTo(Image& im);
};

#endif //TDT4102_CANVAS_H