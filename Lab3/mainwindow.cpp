#include "mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QPainter>
#include <time.h>
#include <math.h>
#include "heat_map.h"

int maxX=500, maxY=500;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene* scene = new QGraphicsScene();

    int onePixDistance = 10; //m
    int TxPower = 23;
    int antGain = 12;
    float freq=2.5;
    srand(time(NULL)); //установка точки 5G New Radio
    int cellPosX =rand()%maxX;
    int cellPosY=rand()%maxY;
    QPixmap map(maxX, maxY); // создаем карту для рисования
    QPainter p(&map);

    Circle wall; //стена
    wall.concrete = true;
    wall.circle(&p, 500, 450, 130);

    Wall Fence; //забор
    Fence.wood = true;
    Fence.wall(&p, 200, 500, 100, 50);

    Square Office; //офис
    Office.doubleglass = true;
    Office.square(&p, 50, 300, 150, 400);

    QImage image = map.toImage();

    Fill_Field(&p, &map,&image, cellPosX, cellPosY, onePixDistance, TxPower, antGain, freq);

    p.setPen(QColor(255, 255, 200, 255)); //нарисованная точка доступа
    p.drawPoint(cellPosX, cellPosY);

    p.end();
    scene->addPixmap(map);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}
