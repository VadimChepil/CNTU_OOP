#include "game.h"
#include <QMessageBox>
#include "QApplication"

Game::Game(QWidget* parent) : QMainWindow(parent), currentLevelNumber(1)
{
    setFixedSize(1300, 730);
    backgroundLabel = new QLabel(this);
    changeRoomBackground(":/pictures/room1.png");
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());
    backgroundLabel->lower();

    QPixmap cursorImage = QPixmap(":pictures/flySwatter.png");
    cursor = QCursor(cursorImage);
    setCursor(cursor);
    startLevel(currentLevelNumber);
}

void Game::changeRoomBackground(const QString& imagePath)
{
    QPixmap newBackground(imagePath);
    backgroundLabel->clear();
    backgroundLabel->setPixmap(newBackground.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Game::startLevel(int levelNumber) {
    if (currentLevel)
    {
        currentLevel->deleteLater();
    }

    currentLevel = new Level(levelNumber, this);
    setCentralWidget(currentLevel);

    connect(currentLevel, &Level::levelCompleted, this, &Game::onLevelCompleted);
    connect(currentLevel, &Level::levelFailed, this, &Game::gameOver);
    currentLevel->show();
}

void Game::onLevelCompleted()
{
    switch (currentLevelNumber)
    {
    case 1:
        QMessageBox::information(this, "Рівень 1 пройдено", "Ви зловили муху! Переходьте на наступний рівень.");
        break;
    case 2:
        QMessageBox::information(this, "Рівень 2 пройдено", "Ви зловили всіх мух, недавши вилетіти у вікно! Переходьте на наступний рівень.");
        changeRoomBackground(":/pictures/room2.png");
        QMessageBox::information(this, "Рівень 3 підготовка", "Ви граєте за жабу ваше завдання зловити надоїдливих мух. "
                                                              "Рухатись можете клавішами w,a,s,d, щоб спіймати муху язиком нажміть x, "
                                                              "наганяючи мух до жаби мухобойкою");
        changeRoomBackground(":/pictures/room1.png");
        break;
    case 3:
        QMessageBox::information(this, "Рівень 3 пройдено", "Ви пройшли гру!");
        QApplication::quit();
        break;
    }
    currentLevelNumber++;
    startLevel(currentLevelNumber);
}

void Game::gameOver()
{
    QMessageBox::information(this, "Рівень провалено", "Ви програли");
    QApplication::quit();
}
