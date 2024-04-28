#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    this->setWindowTitle("Notepad");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    _file_path = "";
    ui->textEdit->setText("");

}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file not open");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MainWindow::on_actionSave_triggered()
{

    QFile file(_file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text;
    file.flush();
    file.close();

}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    _file_path= file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text;
    file.flush();
    file.close();

}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();

}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();

}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();

}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();

}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text = "Notepad is a small and fast notetaking app for making notes, memos, or just any plain text content.\n Features: \n \
                             * simple interface and easy to use \n\
                             * no limits on note's length or number of notes \n\
                             * creating and editing text notes\n\
                             * importing or saving notes from txt files\n";
    QMessageBox::about(this, "Notepad", about_text);

}




