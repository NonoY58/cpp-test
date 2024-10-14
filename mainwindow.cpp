#include "mainwindow.h"
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), rotationAngle(0), isFlipped(true) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Load an image (make sure to provide a valid path to your image)
    originalPixmap.load(":/test_image2.png"); // Use your image file
    imageLabel = new QLabel();
    imageLabel->setPixmap(originalPixmap);
    layout->addWidget(imageLabel);

    QPushButton *rotateButton = new QPushButton("Rotate Image");
    layout->addWidget(rotateButton);
    connect(rotateButton, &QPushButton::clicked, this, &MainWindow::rotateImage);

    QPushButton *flipButton = new QPushButton("Flip Image");
    layout->addWidget(flipButton);
    connect(flipButton, &QPushButton::clicked, this, &MainWindow::flipImage);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::showImage() {
    QTransform transform;
    transform.rotate(rotationAngle);
    transform.scale(isFlipped, 1);
    QPixmap rotatedPixmap = originalPixmap.transformed(transform);
    imageLabel->setPixmap(rotatedPixmap);
}

void MainWindow::rotateImage() {
    rotationAngle += 90; // Increment the angle by 90 degrees
    showImage();
}

void MainWindow::flipImage() {
    isFlipped = isFlipped * -1;
    showImage();

}
