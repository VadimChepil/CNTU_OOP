#ifndef FROG_H
#define FROG_H

#include <QLabel>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QList>

#include "fly.h"

class Frog : public QLabel
{
    Q_OBJECT

public:
    explicit Frog(QWidget* parent = nullptr);

    void keyPressEvent(QKeyEvent* event) override;
    int getCaughtFlies() const;

private:
    int x;
    int y;
    int step;
    bool tongueVisible;
    bool isLeft;
    QLabel* frogTongue;
    QTimer tongueTimer;
    int caughtFlies;


    void updateTonguePosition();
    void checkFlyCollision();
};

#endif // FROG_H
