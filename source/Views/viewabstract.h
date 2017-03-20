#ifndef TOOLBOXABSTRACT_H
#define TOOLBOXABSTRACT_H

#include <QWidget>
#include <QAbstractItemModel>

#include "source/Misc/settingsuser.h"

enum ViewType {Default, ConnectionList,QueryEditor,OutPut};

Q_DECLARE_METATYPE(ViewType)

class ViewAbstract : public QWidget, public SettingsUser
{
public:


    ViewAbstract(QWidget* parent = 0);
    virtual ~ViewAbstract();

    ViewType getViewType();
    void setViewType(const ViewType &vt);

    virtual void setModel(QAbstractItemModel* model) = 0;

protected:

    ViewType viewType;
};

#endif // TOOLBOXABSTRACT_H
