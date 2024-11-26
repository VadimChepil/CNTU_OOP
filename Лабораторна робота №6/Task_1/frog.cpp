#include "frog.h"
#include <QDebug>
#include <QPixmap>

Frog::Frog(QWidget* parent) : QLabel(parent), x(100), y(650), step(10), tongueVisible(false), isLeft(true)
{
    setFocusPolicy(Qt::StrongFocus);
    setPixmap(QPixmap(":/pictures/frog to left.png").scaled(36, 36));
    setGeometry(x, y, 36, 36);

    frogTongue = new QLabel(parent);
    frogTongue->setPixmap(QPixmap(":/pictures/frog tongue to left.png").scaled(10, 70));
    frogTongue->setGeometry(x + 5, y - 36, 10, 70);
    frogTongue->hide();

    connect(&tongueTimer, &QTimer::timeout, [this]() {
        tongueVisible = false;
        frogTongue->hide();
        tongueTimer.stop();
    });
}

void Frog::keyPressEvent(QKeyEvent *event)
{
    if (tongueVisible)
    {
        return;
    }

    switch (event->key())
    {
    case Qt::Key_W:
        if (y > 590)
        {
            y -= step;
        }
        break;
    case Qt::Key_S:
        if (y < (730 - height()))
        {
            y += step;
        }
        break;
    case Qt::Key_A:
        if (x > 0)
        {
            setPixmap(QPixmap(":/pictures/frog to left.png").scaled(36, 36));
            frogTongue->setPixmap(QPixmap(":/pictures/frog tongue to left.png").scaled(10, 70));
            isLeft = true;
            x -= step;
        }
        break;
    case Qt::Key_D:
        if (x < (1300 - width()))
        {
            setPixmap(QPixmap(":/pictures/frog to right.png").scaled(36, 36));
            frogTongue->setPixmap(QPixmap(":/pictures/frog tongue to right.png").scaled(10, 70));
            isLeft = false;
            x += step;
        }
        break;
    case Qt::Key_X:
        if (!tongueVisible)
        {
            tongueVisible = true;
            frogTongue->show();
            checkFlyCollision();
            tongueTimer.start(1000);
        }
        break;
    default:
        QLabel::keyPressEvent(event);
    }

    move(x, y);

    updateTonguePosition();
}

void Frog::updateTonguePosition()
{
    if (isLeft)
    {
        frogTongue->move(x - 10, y - 70);
    }
    else
    {
        frogTongue->move(x + width() - 5, y - 70);
    }
}

void Frog::checkFlyCollision() {
    QList<Fly*> flies = parentWidget()->findChildren<Fly*>();
    for (Fly* fly : flies)
    {
        if (frogTongue->geometry().intersects(fly->geometry()))
        {
            fly->hide();
            caughtFlies++;
        }
    }
}

int Frog::getCaughtFlies() const
{
    return caughtFlies;
}

