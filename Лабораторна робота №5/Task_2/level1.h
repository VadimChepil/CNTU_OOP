#ifndef LEVEL1_H
#define LEVEL1_H

#include "Level.h"
#include "fly.h"

class Level1 : public Level {
public:
    Level1(QObject* parent = nullptr);
    void setupLevel() override;
};

#endif // LEVEL1_H
