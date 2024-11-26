#include "level.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

Level::Level(int levelNumber, QWidget* parent)
    : QWidget(parent), level(levelNumber), trapLabel(nullptr),
    windowLabel(nullptr), fly1(nullptr), fly2(nullptr), fly3(nullptr), frog(nullptr)
{
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    switch (levelNumber)
    {
    case 1:
        Level1();
        break;
    case 2:
        Level2();
        break;
    case 3:
        Level3();
        break;
    default:
        QMessageBox::warning(this, "Error", "Invalid level number");
        break;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Level::updateFliesPosition);
    timer->start(50);
}

bool Level::checkIfFlyCaught()
{
    return (fly1 && fly1->geometry().intersects(trapLabel->geometry())) ||
           (fly2 && fly2->geometry().intersects(trapLabel->geometry())) ||
           (fly3 && fly3->geometry().intersects(trapLabel->geometry()));
}

void Level::Level1()
{
    trapLabel = new QLabel(this);
    trapLabel->setGeometry(625, 415, 80, 80);

    QPixmap trapPixmap(":/pictures/trap.png");
    trapLabel->setPixmap(trapPixmap.scaled(80, 80, Qt::KeepAspectRatio));

    if (!fly1)
    {
        fly1 = new Fly(this);
    }
}

void Level::Level2()
{
    Level1();

    if (!windowLabel)
    {
        windowLabel = new QLabel(this);
        windowLabel->setGeometry(945, 150, 325, 300);
        QPixmap windowPixmap(":/pictures/window.png");
        windowLabel->setPixmap(windowPixmap.scaled(325, 300));
        openWindowZone.setRect(1100, 180, 80, 250);
    }

    if (!fly2)
    {
        fly2 = new SmartFly(this, windowLabel);
    }
}

void Level::Level3()
{
    Level2();

    fly1->setGeometry(1000, 200, 24, 24);

    if (fly2)
    {
        delete fly2;
        fly2 = nullptr;
    }

    if (windowLabel)
    {
        delete windowLabel;
        windowLabel = nullptr;
        openWindowZone.setRect(0, 0, 0, 0);
    }

    if (trapLabel)
    {
        delete trapLabel;
        trapLabel = nullptr;
    }

    if (!fly3)
    {
        fly3 = new Fly(this);
        fly3->setGeometry(600, 300, 24, 24);
    }

    if (!frog)
    {
        frog = new Frog(this);
        frog->setGeometry(100, 650, 36, 36);
    }
}

void Level::stopLevel()
{
    timer->stop();

    if (fly1)
    {
        delete fly1;
        fly1 = nullptr;
    }
    if (fly2)
    {
        delete fly2;
        fly2 = nullptr;
    }
    if (fly3)
    {
        delete fly3;
        fly3 = nullptr;
    }

    if (windowLabel)
    {
        delete windowLabel;
        windowLabel = nullptr;
    }
}

void Level::keyPressEvent(QKeyEvent *event)
{
    if (frog)
    {
        frog->keyPressEvent(event);
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
        if (fly2)
        {
            fly2->moveFly();
        }
        if (fly3)
        {
            fly3->moveRandomly();
        }
        return;
    }

    if (fly2 && openWindowZone.width() > 0 && fly2->geometry().intersects(openWindowZone))
    {
        emit levelFailed();
        stopLevel();
        return;
    }

    if (fly1)
    {
        fly1->moveFly();
    }
    if (fly2)
    {
        fly2->moveFly();
    }
    if (fly3)
    {
        fly3->moveFly();
    }

    if (trapLabel != nullptr)
    {
        if (checkIfFlyCaught())
        {
            emit levelCompleted();
            stopLevel();
        }
    }

    if (frog && frog->getCaughtFlies() == 2)
    {
        emit levelCompleted();
        stopLevel();
    }

}

