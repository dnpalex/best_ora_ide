#ifndef ADAPTERABSTRACT_H
#define ADAPTERABSTRACT_H

#include <QAbstractItemModel>

#include "Views/viewabstract.h"

class AdapterAbstract
{
public:
    AdapterAbstract();
    virtual ~AdapterAbstract();

    virtual void RequestModel(const ViewAbstract::ViewType& viewType) = 0;

    virtual void ModelFinished(QAbstractItemModel* model, const ViewAbstract::ViewType& viewType) = 0;
};

#endif // ADAPTERABSTRACT_H
