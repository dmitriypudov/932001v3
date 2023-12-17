#include "mainwindow.h"

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto widget = new QWidget(this);
    layout = new QVBoxLayout(widget);

    label = new QLabel("Нажмите кнопку");
    graphButton = new QPushButton("Draw graph");

    chart = new QtCharts::QChart();
    series = new QtCharts::QLineSeries(this);

    textEdit = new QTextEdit();
    textEdit->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit");
    textButton = new QPushButton("Find most commod letter");
    mostCommonLetterLabel = new QLabel("Most common letter: ");

    chartView = new QtCharts::QChartView(chart);
    chartView->setFixedSize(800, 600);

    layout->addWidget(label);
    layout->addWidget(graphButton);
    layout->addWidget(chartView);
    layout->addWidget(textEdit);
    layout->addWidget(textButton);
    layout->addWidget(mostCommonLetterLabel);

    connect(graphButton, SIGNAL(clicked()), this, SLOT(drawGraph()));
    connect(textButton, SIGNAL(clicked()), this, SLOT(getMostCommonLetter()));
    this->setCentralWidget(widget);
}

void MainWindow::drawGraph()
{
    float x = 0;
    float step = M_PI / 1000;
    for(int i = 0; i < 1000; i++) {
        series->append(x, sin(x));
        x += step;
    }

    chart->addSeries(series);
    chart->createDefaultAxes();
    chartView->update();
}

void MainWindow::getMostCommonLetter()
{
    QString text = textEdit->toPlainText();

    QMap<QChar, int> charCountMap;

    for (int i = 0; i < text.length(); ++i)
    {
        QChar character = text.at(i);

        if(character != ' ') {
            charCountMap[character]++;
        }
    }

    QChar mostFrequentChar;
    int maxFrequency = 0;

    for(auto letter : charCountMap.keys())
    {
        if (charCountMap.value(letter) > maxFrequency)
        {
            maxFrequency = charCountMap.value(letter);
            mostFrequentChar = letter;
        }
    }

    mostCommonLetterLabel->setText(QString("Most common label: ") + mostFrequentChar);
}
