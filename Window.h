#ifndef WINDOW_H
#define WINDOW_H

#include <QKeyEvent>
#include <QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtCore/QCoreApplication>
#include <QtGui/QTextBlock>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QListView>
#include "Lexer.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QTableWidget>
#include <iostream>
#include "vector"
#include "MemoryObject.h"
#include "Printer.h"


using namespace std;
/**
 * @brief The Window class : Clase que corresponde a la ventana principal
 */
class Window : public QWidget {
Q_OBJECT
public:
    int vecIndex;
    Lexer lexito;
    vector<MemoryObject> memObjVector;

    explicit Window(QWidget *parent = 0);

    QString getEditorReading();

    void RefreshRAMBox();

    void Increment();

    void vectorAdder(std::string Json);

    void printOnConsole();
private slots:

    void RunProgram();

    void StopProgram();

    void NextLine();

    void updateRamViewer();

    void checkScope();

private:

    QPushButton *NextLineButton;

    QPushButton *RunButton;

    QPushButton *StopButton;

    QTableWidget *Table;

    QTextEdit *Log1;

    QTextEdit *Log2;

    QTableWidgetItem *Header1, *Header2, *Header3, *Header4;

    QTextEdit *Code;

};

#endif // WINDOW_H