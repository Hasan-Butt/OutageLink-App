#include "analytics.h"
#include "libs/qcustomplot.h"
#include <QDate>
#include <QMap>
#include <QSharedPointer>


void plotOutagesPerDay(QCustomPlot* plot,
                       const Report* reports, int reportCount)
{
    // 1) Count per date
    QMap<QDate,int> counts;
    for (int i = 0; i < reportCount; ++i) {
        const Report &r = reports[i];
        QDate d(r.year, r.month, r.day);
        counts[d]++;
    }

    // 2) Build data vectors
    QVector<double> x, y;
    QStringList labels;
    int idx = 1;
    for (auto it = counts.cbegin(); it != counts.cend(); ++it) {
        x.push_back(idx);
        y.push_back(it.value());
        labels << it.key().toString("MM-dd");
        ++idx;
    }

    // 3) Plot
    plot->clearPlottables();
    auto *bars = new QCPBars(plot->xAxis, plot->yAxis);
    bars->setData(x, y);
    bars->setWidth(0.6);
    bars->setPen(QPen(Qt::darkBlue));
    bars->setBrush(QColor(100, 150, 255, 180));
    bars->setAntialiased(false);

    // text ticker
    auto ticker = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    for (int i = 0; i < labels.size(); ++i)
        ticker->addTick(x[i], labels[i]);
    plot->xAxis->setTicker(ticker);
    plot->xAxis->setTickLabelRotation(45);

    plot->xAxis->setLabel("Date");
    plot->yAxis->setLabel("Outages");

    // lock to data range
    plot->xAxis->setRange(0.5, labels.size() + 0.5);
    double maxY = y.isEmpty() ? 1 : *std::max_element(y.constBegin(), y.constEnd());
    plot->yAxis->setRange(0, maxY * 1.2);

    plot->replot();
}

void plotOutageTypes(QCustomPlot* plot,
                     const Report* reports, int reportCount)
{
    // 1) Count per type
    QMap<QString,int> counts;
    for (int i = 0; i < reportCount; ++i)
        counts[reports[i].type]++;

    // 2) Build data
    QVector<double> x, y;
    QStringList labels;
    int idx = 1;
    for (auto it = counts.cbegin(); it != counts.cend(); ++it) {
        x.push_back(idx);
        y.push_back(it.value());
        labels << it.key();
        ++idx;
    }

    // 3) Plot
    plot->clearPlottables();
    auto *bars = new QCPBars(plot->xAxis, plot->yAxis);
    bars->setData(x, y);
    bars->setWidth(0.6);
    bars->setPen(QPen(Qt::darkBlue));
    bars->setBrush(QColor(100, 150, 255, 180));
    bars->setAntialiased(false);
    // 4) Text ticker
    auto textTicker = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    for (int i = 0; i < labels.size(); ++i)
        textTicker->addTick(x[i], labels[i]);
    plot->xAxis->setTicker(textTicker);
    plot->xAxis->setTickLabelRotation(30);
    plot->xAxis->setLabel("Outage Type");
    plot->yAxis->setLabel("Count");

    // lock to data range
    plot->xAxis->setRange(0.5, labels.size() + 0.5);
    double maxY = y.isEmpty() ? 1 : *std::max_element(y.constBegin(), y.constEnd());
    plot->yAxis->setRange(0, maxY * 1.2);
    plot->replot();
}

void plotResourceUsage(QCustomPlot* plot,
                       const Resource* resources, int resourceCount)
{
    // 1) Count assigned events
    QMap<QString,int> counts;
    for (int i = 0; i < resourceCount; ++i) {
        if (resources[i].isAssigned)
            counts[resources[i].item]++;
    }

    // 2) Build data
    QVector<double> x, y;
    QStringList labels;
    int idx = 1;
    for (auto it = counts.cbegin(); it != counts.cend(); ++it) {
        x.push_back(idx);
        y.push_back(it.value());
        labels << it.key();
        ++idx;
    }

    // 3) Plot
    plot->clearPlottables();
    auto *bars = new QCPBars(plot->xAxis, plot->yAxis);
    bars->setData(x, y);
    bars->setWidth(0.6);
    bars->setPen(QPen(Qt::darkBlue));
    bars->setBrush(QColor(100, 150, 255, 180));
    bars->setAntialiased(false);

    // 4) Text ticker
    auto textTicker = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
    for (int i = 0; i < labels.size(); ++i)
        textTicker->addTick(x[i], labels[i]);
    plot->xAxis->setTicker(textTicker);
    plot->xAxis->setTickLabelRotation(30);
    plot->xAxis->setLabel("Resource");
    plot->yAxis->setLabel("Times Borrowed");

    plot->xAxis->setRange(0.5, labels.size() + 0.5);
    double maxY = y.isEmpty() ? 1 : *std::max_element(y.constBegin(), y.constEnd());
    plot->yAxis->setRange(0, maxY * 1.2);
    plot->replot();
}
