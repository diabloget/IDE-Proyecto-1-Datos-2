#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "Window.h"

/**
 * @file main.cpp
 * @authors Diabloget, Jjvv21
 */

int main(int argc, char *argv[]) {
    QApplication app (argc, argv);
    QWidget *window = new Window;
    window->show();
    return app.exec();
}
