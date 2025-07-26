#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "data.h"
class QCustomPlot;

/// Plot a bar chart of “Outages per Day”
void plotOutagesPerDay(QCustomPlot* plot,
                       const Report* reports, int reportCount);

/// Plot a bar chart of “Outage Types”
void plotOutageTypes(QCustomPlot* plot,
                     const Report* reports, int reportCount);

/// Plot a bar chart of “Resource Borrow Count”
void plotResourceUsage(QCustomPlot* plot,
                       const Resource* resources, int resourceCount);

#endif // ANALYTICS_H
