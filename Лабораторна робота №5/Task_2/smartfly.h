#ifndef SMARTFLY_H
#define SMARTFLY_H

#include "fly.h"

class SmartFly : public Fly
{
public:
    SmartFly(QWidget* parent, QLabel* target);
    void moveRandomly() override;
    void moveFly();

private:
    QLabel* windowLabel;
};

#endif // SMARTFLY_H
