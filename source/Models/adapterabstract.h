#ifndef ADAPTERABSTRACT_H
#define ADAPTERABSTRACT_H

#include <QAbstractItemModel>

#include "source/Views/viewabstract.h"

class AdapterAbstract
{
public:
    AdapterAbstract();

    virtual void RequestModel(const ViewType& viewType) = 0;

    virtual void ModelFinished(QAbstractItemModel* model, const ViewType& viewType) = 0;
};

#endif // ADAPTERABSTRACT_H
