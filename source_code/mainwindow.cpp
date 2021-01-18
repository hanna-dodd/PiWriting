/** 
*   @brief      MainWindow class implementation.
*   @details    Button functions for the main pages of the application.
*   @author     Jerrie Berrafati
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileHandler.h"
#include "File.h"
#include "Converter.h"
#include "Output.h"
#include "Translator.h"
#include "email.h"
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <fstream>
#include <QMessageBox>
#include <QTimer>

/**
*   @brief      Constructor.
*   @details    Creates Main Window object.
*   @param      Qtwidget - parent of the main window
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
*   @brief      Destructor.
*   @details    Destroys Main Window object.
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/**
*   @brief      Functionality of the select image button. 
*   @details    Allows the user to choose a .png or .jpeg file from a directory and converts that
                image into an Output object.
*/
void MainWindow::on_select_file_btn_clicked()
{
    // Filter for only png and jpg images
    QString png_filter = "png(*.png *.jpg)";

    // Opens the menu to choose a file
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), png_filter);
    QFile file(file_name);

    // Conversion to std string
    std::string std_text = file_name.toStdString();

    std::cout << std_text << std::endl;

    // If a file is selected
    if (!file_name.isEmpty() && !file_name.isNull()){
        ui->stackedWidget->setCurrentIndex(1);
        ui->label_8->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_9->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_14->setVisible(false);
        ui->label_12->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->pushButton_6->setVisible(false);

        // Call to readimage for conversion
        File image(std_text, "img");

        Converter imageconvert;
        output = imageconvert.imagetostring(image);

        std::string newtext = output.getText();
        output.setString(newtext);
        std::cout << newtext << std::endl;

        // Converts back to QString and sends to text edit window on page 2
        QString text = QString::fromStdString(newtext);
        ui->textEdit->setPlainText(text);
    }

    // If cancel is selected, do nothing
    else{
        std::cout << "User selected cancel in file chooser!" << std::endl;
    }
}


/**
*   @brief      Functionality of the play audio button. 
*   @details    Calls the playaudio function on the current output object.
*/
void MainWindow::on_pushButton_clicked()
{
    QString temp = ui->textEdit->toPlainText();
    std::string text = temp.toStdString();

    std::cout << "Speaking: " << text << std::endl;

    // Call writetoaudio with (text)
    handler.playaudio(output);
    ui->label_8->show();
    QTimer::singleShot(3000, ui->label_8, &QWidget::hide);
}


/**
*   @brief      Functionality of the write to audio button. 
*   @details    Calls the writetoaudio function on the current output object.
*/
void MainWindow::on_pushButton_2_clicked()
{
    QString temp = ui->textEdit->toPlainText();
    std::string text = temp.toStdString();

    handler.writetoaudio(output);
    ui->label_10->show();
    QTimer::singleShot(3000, ui->label_10, &QWidget::hide);
}


/**
*   @brief      Functionality of the write to text button. 
*   @details    Calls the writetotxt function on the current output object.
*/
void MainWindow::on_pushButton_3_clicked()
{
    handler.writetotxt(output);
    ui->label_11->show();
    ui->label_14->setVisible(true);
    ui->label_13->setVisible(true);
    ui->label_12->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->pushButton_6->setVisible(true);
    QTimer::singleShot(3000, ui->label_11, &QWidget::hide);
}

/**
*   @brief      Back button. 
*   @details    Changes the current page index to return to a previous page.
*/
void MainWindow::on_pushButton_4_clicked()
{
    int curr = this->ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(curr - 1);
}

/**
*   @brief      Send email button. 
*   @details    Sends email with the given file.
*/
void MainWindow::on_pushButton_6_clicked()
{
    QString temp = ui->lineEdit->text();
    // Name entered by user
    std::string name = temp.toStdString();

    std::cout << name << std::endl;

    QString temp1 = ui->lineEdit_2->text();
    // Email address entered by user
    std::string address = temp1.toStdString();

    std::cout << address << std::endl;

    // Call to sendemail function goes here
    // if we are going to allow the user to use their own email address and just put the restrictions in the README
    // then user has to provide a password aswell then:
    // email emailobj(address, password, name)

    // if we are using a hardcoded email then:
    email emailobj("cs3307group16testacct@outlook.com", "westerntestaccount5!", "cs cs2");

    std::string filename = "export.txt";
    // Call to sendemail function goes here
    emailobj.sendmail(name, address, filename);

    ui->label_15->show();
    QTimer::singleShot(3000, ui->label_15, &QWidget::hide);
}


/**
*   @brief      French translation radio button. 
*   @details    Translates the current output object to French.
*/
void MainWindow::on_radioButton_clicked()
{
    std::string langto = "fr";
    std::string langfrom = "en";

    // Call to translate function
    Translator obj = Translator(langto, langfrom);
    Output translated = obj.translate(output, langto);
    std::string transtext = translated.getText();
    translated.setString(transtext);

    // Converts back to QString and sends to text edit window on page 2
    QString text = QString::fromStdString(transtext);
    ui->textEdit_2->setPlainText(text);
}

/**
*   @brief      Spanish translation radio button. 
*   @details    Translates the current output object to Spanish.
*/
void MainWindow::on_radioButton_2_clicked()
{
    std::string langto = "es";
    std::string langfrom = "en";

    // Call to translate function
    Translator obj = Translator(langto, langfrom);
    Output translated = obj.translate(output, langto);
    std::string transtext = translated.getText();
    translated.setString(transtext);

    // Call to translate function

    // Converts back to QString and sends to text edit window on page 2
    QString text = QString::fromStdString(transtext);
    ui->textEdit_2->setPlainText(text);
}


/**
*   @brief      Functionality of the write to doc button. 
*   @details    Calls the writetodoc function on the current output object.
*/
void MainWindow::on_pushButton_5_clicked()
{
    handler.writetodoc(output);
    ui->label_9->show();
    QTimer::singleShot(3000, ui->label_9, &QWidget::hide);
}


/**
*   @brief      Check email button. 
*   @details    Check email and downloads attachments.
*/
void MainWindow::on_select_file_btn_2_clicked()
{

    // Call functions for check mail here

    email emailobj("cs3307group16testacct@outlook.com", "westerntestaccount5!", "cs cs2");
    
    emailobj.getmail();
    
    // Filter for only png and jpg images
    QString png_filter = "png(*.png *.jpg)";

    // Opens the menu to choose a file
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), png_filter);
    QFile file(file_name);

    // Conversion to std string
    std::string std_text = file_name.toStdString();

    std::cout << std_text << std::endl;

    // If a file is selected
    if (!file_name.isEmpty() && !file_name.isNull()){
        ui->stackedWidget->setCurrentIndex(1);
        ui->label_8->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_9->setVisible(false);
        ui->label_15->setVisible(false);

        // Call to readimage for conversion
        File image(std_text, "img");

        Converter imageconvert;
        output = imageconvert.imagetostring(image);

        std::string newtext = output.getText();
        output.setString(newtext);
        std::cout << newtext << std::endl;

        // Converts back to QString and sends to text edit window on page 2
        QString text = QString::fromStdString(newtext);
        ui->textEdit->setPlainText(text);
    }

    // If cancel is selected, do nothing
    else{
        std::cout << "User selected cancel in file chooser!" << std::endl;
    }
}
