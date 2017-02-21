#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "source/Misc/settingsuser.h"

class TreeModel : public QAbstractItemModel, public SettingsUser
{
public:
    TreeModel(QObject* parent);
};

#endif // TREEMODEL_H
