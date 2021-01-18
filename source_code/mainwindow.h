/** 
*   @brief      MainWindow class.
*   @details    Button functions for the main pages of the application.
*   @author     Jerrie Berrafati
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Output.h"
#include "FileHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    /// Main Window
    Ui::MainWindow *ui;

    /// Current output object.
    Output output;

    /// File Handler
    FileHandler handler;

public:

    /// Constructor.
    MainWindow(QWidget *parent = nullptr);

    /// Destructor.
    ~MainWindow();

private slots:

    /// Select image button.
    void on_select_file_btn_clicked();

    /// Play audio button.
    void on_pushButton_clicked();

    /// Write to audio button.
    void on_pushButton_2_clicked();

    /// Write to text button.
    void on_pushButton_3_clicked();

    /// Back button.
    void on_pushButton_4_clicked();

    /// Send email button.
    void on_pushButton_6_clicked();

    /// Translate to French button.
    void on_radioButton_clicked();

    /// Translate to Spanish button.
    void on_radioButton_2_clicked();

    /// Write to doc button.
    void on_pushButton_5_clicked();

    /// Check mail button.
    void on_select_file_btn_2_clicked();

};
#endif // MAINWINDOW_H
