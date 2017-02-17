#ifndef TOOLBOXABSTRACT_H
#define TOOLBOXABSTRACT_H

#include <QWidget>
#include "source/Misc/settingsuser.h"

enum ViewType {Default, ConnectionList,QueryEditor,OutPut};

class ViewAbstract : public QWidget, public SettingsUser
{
public:
    ViewAbstract(QWidget* parent = 0);
    virtual ~ViewAbstract();

    ViewType getViewType();
    void setViewType(ViewType vt);

protected:

    ViewType viewType;
};

#endif // TOOLBOXABSTRACT_H
