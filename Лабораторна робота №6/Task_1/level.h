#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

#include "fly.h"
#include "smartfly.h"
#include "frog.h"

class Level : public QWidget {
    Q_OBJECT

public:
    Level(int levelNumber, QWidget* parent = nullptr);

signals:
    void levelCompleted();
    void levelFailed();

private slots:
    void updateFliesPosition();

private:
    int level;
    QTimer* timer;
    QLabel* trapLabel;
    QLabel* windowLabel;
    Fly* fly1;
    SmartFly* fly2;
    Fly* fly3;
    Frog* frog;
    QRect openWindowZone;

    bool checkIfFlyCaught();
    void Level1();
    void Level2();
    void Level3();
    void stopLevel();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // LEVEL_H
