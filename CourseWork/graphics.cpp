#include "graphics.h"
#include "ui_graphics.h"
#include "utils.h"
#include <fstream>
#include "qcustomplot.h"
#include <QVector>
//#include <QCPGraphData>

Graphics::Graphics(QWidget *parent, int index) :
    QDialog(parent),
    ui(new Ui::Graphics)
{
    ui->setupUi(this);
    this->index = index;

    int timeIndex = utils::whatTimeIndex();
    QVector<QString> names = {"Yandex", "Apple","Samsung", "VTB", "Sber", "Sony"};
    std::ifstream File("PriceList.txt" );
    std::vector<std::vector<double>> prices = utils::parseData(File);
    std::vector<double> data = prices[index];
    QVector<double> time1;
    QVector<double> datas;
    double max = 0;

    double now = QDateTime::currentDateTime().toTime_t();
    double startDay = now - timeIndex * 60;

    for (int i = 0;i < timeIndex; ++i){
        datas.push_back(data.at(i));
        time1.push_back(startDay + i*60);
        if(max < datas.at(i))
            max = datas.at(i);
    }


    QTime beginTime(9,0);
    QTime endTime(19,0);

    customPlot = new QCustomPlot();
    ui->gridLayout->addWidget(customPlot,0,0,1,1);
    customPlot->addGraph();
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen pen;
    pen.setColor(QColor(255, 200, 20, 200));
    //pen.setStyle(Qt::);
    pen.setWidthF(2.5);
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setBrush(QBrush(QColor(255,200,20,70)));
    // set graph name, will show up in legend next to icon:
    customPlot->graph()->setName(names[index]);
    // set data:
    customPlot->graph()->setData(time1, datas);

    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);   // Подпись координат по Оси X в качестве Даты и Времени
    customPlot->xAxis->setDateTimeFormat("hh:mm");  // Устанавливаем формат даты и времени

    // axis configurations:
    customPlot->xAxis->setLabel("Time");
    customPlot->yAxis->setLabel("Price");
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis->setRange(startDay, now);
    //customPlot->rescaleAxes();
    customPlot->yAxis->setRange(0, max+20);


    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),
            this, SLOT(slotRangeChanged(QCPRange)));

    // setup legend:
    customPlot->legend->setFont(QFont(font().family(), 7));
    customPlot->legend->setIconSize(30, 30);
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
    customPlot->replot();
}

Graphics::~Graphics()
{
    delete ui;
}

void Graphics::slotRangeChanged(const QCPRange &newRange)
{
    /* Если область видимости графика меньше одного дня,
     * то отображаем часы и минуты по Оси X,
     * в противном случае отображаем дату "День Месяц Год"
     * */
    customPlot->xAxis->setDateTimeFormat((newRange.size() <= 86400)? "hh:mm" : "dd MMM yy");
}

