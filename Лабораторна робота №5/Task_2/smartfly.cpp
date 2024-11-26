#include "smartfly.h"

SmartFly::SmartFly(QWidget* parent, QLabel* target) : Fly(parent), windowLabel(target) {}

void SmartFly::moveRandomly() {
    int X = QRandomGenerator::global()->bounded(-5, 5);
    int Y = QRandomGenerator::global()->bounded(-5, 5);

    int newX = qBound(0, x() + X, parentWidget()->width() - width());
    int newY = qBound(0, y() + Y, parentWidget()->height() - height());

    move(newX, newY);
}

void SmartFly::moveFly()
{
    QPoint windowPos = parentWidget()->mapFromGlobal(windowLabel->mapToGlobal(windowLabel->rect().center()));
    QPoint cursorPos = parentWidget()->mapFromGlobal(QCursor::pos());

    int windowX = windowPos.x();
    int windowY = windowPos.y();

    int mouseX = cursorPos.x();
    int mouseY = cursorPos.y();

    int flyX = this->x();
    int flyY = this->y();

    int distanceWindowX = windowX - flyX;
    int distanceWindowY = windowY - flyY;

    int distanceCursorX = mouseX - flyX;
    int distanceCursorY = mouseY - flyY;

    int distanceSquared = distanceCursorX * distanceCursorX + distanceCursorY * distanceCursorY;

    if (distanceSquared < 2500)
    {
        flyX += (distanceCursorX < 0) ? 5 : -5;
        flyY += (distanceCursorY < 0) ? 5 : -5;
    }
    else
    {
        flyX += (distanceWindowX > 0) ? 5 : -5;
        flyY += (distanceWindowY > 0) ? 5 : -5;
    }

    flyX = qBound(0, flyX, parentWidget()->width() - width());
    flyY = qBound(0, flyY, parentWidget()->height() - height());

    this->move(flyX, flyY);
    this->moveRandomly();
}

