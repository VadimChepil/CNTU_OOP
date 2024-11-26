#include "fly.h"

Fly::Fly(QWidget* parent) : QLabel(parent) {
    setPixmap(QPixmap(":/pictures/fly.png").scaled(24, 24));
    setGeometry(200, 600, 24, 24);
}

void Fly::moveRandomly() {
    int X = QRandomGenerator::global()->bounded(-5, 5);
    int Y = QRandomGenerator::global()->bounded(-5, 5);

    int newX = qBound(0, x() + X, parentWidget()->width() - width());
    int newY = qBound(0, y() + Y, parentWidget()->height() - height());

    move(newX, newY);
}

void Fly::moveFly()
{
    QPoint cursorPos = parentWidget()->mapFromGlobal(QCursor::pos());

    int mouseX = cursorPos.x();
    int mouseY = cursorPos.y();

    int flyX = this->x();
    int flyY = this->y();

    int distanceX = mouseX - flyX;
    int distanceY = mouseY - flyY;

    int distanceSquared = distanceX * distanceX + distanceY * distanceY;

    if (distanceSquared < 2500)
    {
        flyX += (distanceX < 0) ? 10 : -10;
        flyY += (distanceY < 0) ? 10 : -10;
    }
    else
    {
        this->moveRandomly();
        return;
    }

    flyX = qBound(0, flyX, parentWidget()->width() - width());
    flyY = qBound(0, flyY, parentWidget()->height() - height());

    this->move(flyX, flyY);
}
