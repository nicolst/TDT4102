#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "Vector.h"
#include "Rectangle.h"
#include "Canvas.h"
//inkluder andre headerfiler du lager
using namespace std;

int main(){
    //Skriv kode her
    Matrix m(3, 3, 8);
    Vector v(Matrix(3, 1, 5));

    cout << m * v << endl;

    Image im1(5, 5);
    im1.fill(Color(193, 84, 193));
    saveImage(im1, "im1.bmp");

    Image im2(5, 5);
    im2.setPixelColor(2, 2, Color(255, 0, 0));
    saveImage(im2, "im2.bmp");

    Line l1(Color(255, 255, 255), Point(0, 0), Point(100, 50));
    Line l2(Color(255, 255, 255), Point(0, 0), Point(100, 200));

    Image im3(101, 51);
    Image im4(101, 201);

    l1.draw(im3);
    l2.draw(im4);

    saveImage(im3, "im3.bmp");
    saveImage(im4, "im4.bmp");

    Rectangle r1(Line(Color(255, 255, 255), Point(25, 25), Point(75, 75)));
    Image im5(100, 100);
    r1.draw(im5);
    saveImage(im5, "im5.bmp");

    Canvas canvas;
    Rectangle leftEye(Line(Color(255, 255, 255), Point(20, 60), Point(40, 80)));
    Rectangle rightEye(Line(Color(255, 255, 255), Point(60, 60), Point(80, 80)));
    Line bottomMouth(Color(255, 255, 255), Point(40, 20), Point(60, 20));
    Line leftMouth(Color(255, 255, 255), Point(20, 25), Point(40, 20));
    Line rightMouth(Color(255, 255, 255), Point(60, 20), Point(80, 25));

    canvas.addShape(&leftEye);
    canvas.addShape(&rightEye);
    canvas.addShape(&bottomMouth);
    canvas.addShape(&leftMouth);
    canvas.addShape(&rightMouth);

    Image im6(100, 100);
    canvas.rasterizeTo(im6);

    saveImage(im6, "im6.bmp");

    return 0;
}
