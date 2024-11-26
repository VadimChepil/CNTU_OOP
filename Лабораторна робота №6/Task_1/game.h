#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>

#include "level.h"

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
    QLabel* backgroundLabel;
    QCursor cursor;

    void changeRoomBackground(const QString& imagePath);
    void startLevel(int levelNumber);
};

#endif // GAME_H
