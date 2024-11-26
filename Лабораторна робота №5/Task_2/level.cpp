#include "level.h"
#include <QMessageBox>
#include <QPixmap>

Level::Level(int levelNumber, QWidget* parent) : QWidget(parent), level(levelNumber)
{
    setFixedSize(1000, 600);

    if (levelNumber > 1) {
        windowLabel = new QLabel(this);
        windowLabel->setGeometry(500, 500, 80, 80);

        QPixmap windowPixmap(":/pictures/window.png");
        windowLabel->setPixmap(windowPixmap.scaled(80, 80, Qt::KeepAspectRatio));
    }

    trapLabel = new QLabel(this);
    trapLabel->setGeometry(600, 100, 80, 80);

    QPixmap trapPixmap(":/pictures/trap.png");
    trapLabel->setPixmap(trapPixmap.scaled(80, 80, Qt::KeepAspectRatio));

    fly1 = new Fly(this);

    if (levelNumber > 1)
    {
        delete fly1;
        fly1 = nullptr;
        fly2 = new SmartFly(this, windowLabel);
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Level::updateFliesPosition);
    timer->start(50);
}

bool Level::checkIfFlyCaught()
{
    return (fly1 && fly1->geometry().intersects(trapLabel->geometry())) ||
           (fly2 && fly2->geometry().intersects(trapLabel->geometry()));
}

void Level::stopLevel()
{
    timer->stop();

    if (fly1)
    {
        delete fly1;
        fly1 = nullptr;
    }
    else if (fly2)
    {
        delete fly2;
        fly2 = nullptr;
    }
}

void Level::updateFliesPosition()
{
    QPoint cursorPos = parentWidget()->mapFromGlobal(QCursor::pos());

    QRect gameRect = parentWidget()->rect();
    if (!gameRect.contains(cursorPos))
    {
        if (fly1)
        {
            fly1->moveRandomly();
        }
        else if (fly2)
        {
            fly2->moveFly();
        }
        return;
    }

    if (fly2 && fly2->geometry().intersects(windowLabel->geometry()))
    {
        emit levelFailed();
        stopLevel();
        return;
    }

    if (fly1)
    {
        fly1->moveFly();
    }
    else if (fly2)
    {
        fly2->moveFly();
    }

    if (checkIfFlyCaught())
    {
        emit levelCompleted();
        stopLevel();
    }
}

