#ifndef TOOLBOXABSTRACT_H
#define TOOLBOXABSTRACT_H

#include <QSettings>
#include <QWidget>

enum ViewType {Default, ConnectionList,QueryEditor,OutPut};

class ViewAbstract : public QWidget
{
public:
    ViewAbstract(QWidget* parent = 0);
    ViewAbstract(ViewType vt, QString windowName = tr("ToolBox"), QWidget* parent = 0);
    virtual ~ViewAbstract();

    ViewType getViewType();

protected:

    QSettings sets;
    ViewType viewType;
};

#endif // TOOLBOXABSTRACT_H
