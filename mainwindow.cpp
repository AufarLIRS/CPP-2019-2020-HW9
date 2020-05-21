#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::on_selectFilePushButton_clicked()
{
  ui->pathLineEdit->setText(QFileDialog::getOpenFileName(0, "get file", ""));
  ptr = std::make_unique<CustomFile>();
}

void MainWindow::on_selectFolderPushButton_clicked()
{
  QString path = QFileDialog::getExistingDirectory(0, "get folder", "");
  ui->pathLineEdit->setText(path);
  ptr = std::make_unique<CustomFolder>();
}

void MainWindow::on_Print_clicked()
{
  ptr->setPath(ui->pathLineEdit->text());
  ui->outputPlainTextEdit->setPlainText("");
  if (!ui->pathLineEdit->text().isEmpty())
  {
    ui->outputPlainTextEdit->setPlainText(ptr->print());
  }
}
