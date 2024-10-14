#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showImage();
    void rotateImage();
    void flipImage();

private:
    QLabel *imageLabel;
    QPixmap originalPixmap;
    int rotationAngle;
    int isFlipped;
};

#endif // MAINWINDOW_H
