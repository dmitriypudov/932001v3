#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QDebug>
#include <QParallelAnimationGroup>
#include <QVBoxLayout>
#include <QTextEdit>

#include <iostream>

#include <cmath>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void drawGraph();
    void getMostCommonLetter();

private:
    QLabel *label;
    QPushButton *graphButton;
    QPushButton *textButton;
    QVBoxLayout *layout;
    QTextEdit *textEdit;
    QLabel *mostCommonLetterLabel;

    // Для графика
    QtCharts::QChart *chart;
    QtCharts::QLineSeries *series;
    QtCharts::QChartView *chartView;
};
#endif // MAINWINDOW_H
