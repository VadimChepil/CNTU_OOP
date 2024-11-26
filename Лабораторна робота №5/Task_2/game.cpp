#include "game.h"
#include <QMessageBox>
#include "QApplication"

Game::Game(QWidget* parent) : QMainWindow(parent), currentLevelNumber(1) {

    QPixmap cursorImage = QPixmap(":pictures/flySwatter.png");
    cursor = QCursor(cursorImage);
    setCursor(cursor);
    startLevel(currentLevelNumber);
}

void Game::startLevel(int levelNumber) {
    if (currentLevel)
    {
        currentLevel->deleteLater();
    }

    currentLevel = new Level(levelNumber, this);
    setCentralWidget(currentLevel);
    setFixedSize(currentLevel->size());

    connect(currentLevel, &Level::levelCompleted, this, &Game::onLevelCompleted);
    connect(currentLevel, &Level::levelFailed, this, &Game::gameOver);
    currentLevel->show();
}

void Game::onLevelCompleted()
{
    if (currentLevelNumber > 1)
    {
        QMessageBox::information(this, "Рівень пройдено", "Ви пройшли гру");
        QApplication::quit();
    }
    else
    {
        QMessageBox::information(this, "Рівень пройдено", "Ви зловили муху! Переходьте на наступний рівень.");
    }
    currentLevelNumber++;
    startLevel(currentLevelNumber);
}

void Game::gameOver()
{
    QMessageBox::information(this, "Рівень провалено", "Муха вилетіла у вікно");
    QApplication::quit();
}
