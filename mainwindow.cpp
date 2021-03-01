#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <gscene.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new gscene();
   ui->graphicsView->setScene(scene);
   scene->setSceneRect(0,0, ui->graphicsView->width(), ui->graphicsView->height());
   ///q3dsurface
   /// QSplineSeries
   /// http://www.prog.org.ru/topic_30012_0.html
   /// https://habr.com/ru/post/324968/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    scene->i=0;
}



void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
}
