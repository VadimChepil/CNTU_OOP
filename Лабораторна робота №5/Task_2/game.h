#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "level.h"
#include <QPixmap>

class Game : public QMainWindow {
    Q_OBJECT

public:
    Game(QWidget* parent = nullptr);

private slots:
    void onLevelCompleted();
    void gameOver();

private:
    int currentLevelNumber;
    Level* currentLevel = nullptr;
    QCursor cursor;

    void startLevel(int levelNumber);
};

#endif // GAME_H
