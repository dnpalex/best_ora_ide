#ifndef TOOLBOXABSTRACT_H
#define TOOLBOXABSTRACT_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QDomDocument>
#include <QMetaEnum>
#include <QMetaObject>

#include "source/Misc/settingsuser.h"


class ViewAbstract : public QWidget
{
    Q_OBJECT

public:
    enum ViewType {Default, ConnectionList,QueryEditor,OutPut};
    Q_ENUM(ViewType)

    ViewAbstract(QWidget* parent = 0);
    virtual ~ViewAbstract();

    ViewAbstract::ViewType getViewType() const;
    QString getViewTypeStr() const;

    void ApplySettings(const QDomElement& root);

    void setViewType(const ViewAbstract::ViewType &vt);
    virtual void setModel(QAbstractItemModel* model) = 0;

protected:

    ViewType viewType;
};

#endif // TOOLBOXABSTRACT_H
