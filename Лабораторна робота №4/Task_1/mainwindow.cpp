#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), isPressed(false)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPixmap cursorImage1 = QPixmap(":pictures/flySwatter1.png");
    QPixmap cursorImage2 = QPixmap(":pictures/flySwatter2.png");
    cursor1 = QCursor(cursorImage1);
    cursor2 = QCursor(cursorImage2);
    setCursor(cursor1);


    trap = new QLabel(this);
    QPixmap trapImage = QPixmap(":/pictures/trap2.png");
    trapImage = trapImage.scaled(64, 64, Qt::KeepAspectRatio ,Qt::SmoothTransformation);
    trap->setPixmap(trapImage);
    trap->setGeometry(400, 300, 64, 64);


    fly = new QLabel(this);
    QPixmap flyImage = QPixmap(":/pictures/fly.png");
    flyImage = flyImage.scaled(24, 24, Qt::KeepAspectRatio ,Qt::SmoothTransformation);
    fly->setPixmap(flyImage);
    fly->setGeometry(128, 128, 24, 24);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveFly);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !isPressed)
    {
        setCursor(cursor2);
        isPressed = true;
        grabMouse();
    }
}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isPressed)
    {
        setCursor(cursor1);
        isPressed = false;
        releaseMouse();
    }
}

/*bool MainWindow::MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::MouseMove)
    {
        moveFly();
    }

    return QMainWindow::event(e);
}*/

void MainWindow::moveFly()
{
    QPoint cursorPos = mapFromGlobal(QCursor::pos());
    int mouseX = cursorPos.x();
    int mouseY = cursorPos.y();

    int flyX = fly->x();
    int flyY = fly->y();

    int distanceX = mouseX - flyX;
    int distanceY = mouseY - flyY;

    if (distanceX < 100 && distanceY < 100)
    {
        flyX += (distanceX < 0) ? 20 : -20;
        flyY += (distanceY < 0) ? 20 : -20;
    }

    flyX = qBound(0, flyX, width() - fly->width());
    flyY = qBound(0, flyY, height() - fly->height());

    fly->move(flyX, flyY);

    checkCollision();
}

void MainWindow::checkCollision()
{
    if (fly->geometry().intersects(trap->geometry()))
    {
        QMessageBox::information(this, "Game over", "You caught a fly!");
        qApp->quit();
    }
}


