#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "WavReader.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    WavReader reader;

    QVector<double> time = reader.readTime("D:\\Study\\Cpp\\Julia\\wav-reader\\test.wav");
    QVector<double> samples = reader.readSamples("D:\\Study\\Cpp\\Julia\\wav-reader\\test.wav");

    // create graph and assign data to it: створення вікна де будують графік
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(time, samples); //график не может уйти меньше ноля
    // give the axes some labels: дать осям несколько меток:
    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->yAxis->setLabel("Sample");
    // set axes ranges, so we see all data:установить диапазоны осей, чтобы мы увидели все данные:
    ui->customPlot->xAxis->setRange(0, time.length());
    ui->customPlot->yAxis->setRange(-1, 1);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

