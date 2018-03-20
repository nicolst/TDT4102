//
// Created by Nicolai Stølen on 20/03/2018.
//

#include "Canvas.h"

void Canvas::addShape(Shape *shape) {
    shapes.push_back(shape);
}

void Canvas::rasterizeTo(Image &im) {
    for (Shape* shape : shapes) {
        shape->draw(im);
    }
}