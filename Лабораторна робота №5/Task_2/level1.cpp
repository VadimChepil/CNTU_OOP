#include "Level1.h"

Level1::Level1(QObject* parent) {
    scene = new QGraphicsScene();
    setupLevel();
}

void Level1::setupLevel() {
    scene->setSceneRect(0, 0, 800, 600);

    Player* player = new Player();
    scene->addItem(player);
    player->setPos(100, 100); // Початкова позиція гравця
}
