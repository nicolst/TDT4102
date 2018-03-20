//
// Created by Nicolai Stølen on 20/03/2018.
//

#include "Rectangle.h"

Rectangle::Rectangle(Line diagonal): Shape(diagonal.getColor()), diagonal(diagonal) {}

void Rectangle::draw(Image &im) {
    for (int i = diagonal.getStart().x; i <= diagonal.getEnd().x; i++) {
        for (int j = diagonal.getStart().y; j <= diagonal.getEnd().y; j++) {
            im.setPixelColor(i, j, getColor());
        }
    }
}