#ifndef FLY_H
#define FLY_H

#include <QLabel>
#include <QCursor>
#include <QPixmap>
#include <QPoint>
#include <QRandomGenerator>


class Fly : public QLabel
{
    Q_OBJECT
public:
    Fly(QWidget* parent = nullptr);
    virtual void moveRandomly();
    void moveFly();
};

#endif // FLY_H
