#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = 0);

    void ShowMainView();

signals:

public slots:
};

#endif // MAINPRESENTER_H
