#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPixmap>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QEvent>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
   // bool event(QEvent *e);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QCursor cursor1;
    QCursor cursor2;
    bool isPressed;
    QLabel *trap;
    QLabel *fly;


    void moveFly();
    void checkCollision();
};
#endif // MAINWINDOW_H
