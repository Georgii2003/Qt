#ifndef HEAT_MAP_H
#define HEAT_MAP_H
#include "mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QPainter>
#include <time.h>
#include <math.h>

float PL(float f, float d){}

float delay(int N, float f){}

int DrawPixel(QPainter* Pix, int x, int y){}

int* N_of_obstructions(QPainter* Pix, QPixmap* Map, int *Number, int x0, int x1, int y0, int y1) {}

class Obstruction { //препятствия
public:
    bool irrglass; //IRR стекло
    bool doubleglass; //стеклопакет
    bool concrete; //бетон
    bool wood; //дерево
};

class Wall: public Obstruction
{
public:
    void wall(QPainter* Pix, int x0, int x1, int y0, int y1); //линия
};

class Circle: public Obstruction
{
public:
    void circle(QPainter* Pix, int X1, int Y1, int R); //круг
};

class Square: public Obstruction
{
public:
    void square(QPainter* Pix, int x0, int x1, int y0, int y1); //прямоугольник

};

void Pen_Color (QPainter* p,float sigPower);

void Fill_Field(QPainter* p, QPixmap* map,QImage* image, int cellPosX, int cellPosY, int onePixDistance, int TxPower, int antGain, float freq);


#endif // heat_map_H
