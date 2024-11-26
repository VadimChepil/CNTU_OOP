#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "fly.h"
#include "smartfly.h"

class Level : public QWidget {
    Q_OBJECT

public:
    Level(int levelNumber, QWidget* parent = nullptr);
    bool checkIfFlyCaught();
    void stopLevel();

signals:
    void levelCompleted();
    void levelFailed();

private slots:
    void updateFliesPosition();

private:
    int level;
    QLabel* windowLabel = nullptr;
    QLabel* trapLabel;
    Fly* fly1;
    SmartFly* fly2 = nullptr;
    QTimer* timer;
};

#endif // LEVEL_H
