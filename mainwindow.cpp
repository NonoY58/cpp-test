#include "mainwindow.h"
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), rotationAngle(0) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Load an image (make sure to provide a valid path to your image)
    originalPixmap.load(":/test_image.png"); // Use your image file
    imageLabel = new QLabel();
    imageLabel->setPixmap(originalPixmap);
    layout->addWidget(imageLabel);

    QPushButton *rotateButton = new QPushButton("Rotate Image");
    layout->addWidget(rotateButton);
    connect(rotateButton, &QPushButton::clicked, this, &MainWindow::rotateImage);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::rotateImage() {
    rotationAngle += 90; // Increment the angle by 90 degrees
    QTransform transform;
    transform.rotate(rotationAngle);
    QPixmap rotatedPixmap = originalPixmap.transformed(transform);
    imageLabel->setPixmap(rotatedPixmap);
}
