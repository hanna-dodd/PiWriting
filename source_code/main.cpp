/** 
*   @brief      Main class implementation.
*   @details    Starts the Qt application.
*   @author     Jerrie Berrafati
*/
#include "mainwindow.h"

#include <QApplication>

/**
*	@brief		Main Function
*	@details	Driver function, creates Qt application and the main window.
*/
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
