//
// Created by Nicolai Stølen on 20/03/2018.
//

#include <cmath>
#include <iostream>
#include "Line.h"

Line::Line(Color color, Point start, Point end): Shape(color), start(start), end(end), diff(end-start) {}

void Line::draw(Image &im) {
    bool vertical = diff.y > diff.x;
    double slope = (vertical ? 1.0 * diff.x / diff.y : 1.0 * diff.y / diff.x);

    int start1 = (vertical ? start.y : start.x);
    int end1 = (vertical ? end.y : end.x);
    int start2 = (vertical ? start.x : start.y);

    for (int i = start1; i <= end1; i++) {
        auto otherCoord = static_cast<int>(slope * (i - start1) + start2);
        im.setPixelColor((vertical ? otherCoord : i), (vertical ? i : otherCoord), getColor());
    }
}

Point Line::getStart() {
    return start;
}

Point Line::getEnd() {
    return end;
}
