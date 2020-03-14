#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->SelectionButtonGroup->setId(ui->StaticRadioButton, 1);
  ui->SelectionButtonGroup->setId(ui->CustomRadioButton, 2);
}

void MainWindow::on_SelectDirectoryPushButton_clicked()
{
  ui->DirectoryLineEdit->setText(QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
  ptr = std::make_unique<Directory>();
  ptr->SetPath(ui->DirectoryLineEdit->text());
}

void MainWindow::on_SelectFilePushButton_clicked()
{
  if (ui->SelectionButtonGroup->checkedId() == 1)
  {
    ui->DirectoryLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "C:/", tr("All files (*.*)")));
  }
  else
  {
    ui->DirectoryLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "C:/",
                                                                tr("All files (*.*)\r\n"
                                                                   "Documents (*.txt)\r\n"
                                                                   "Images (*.png, *.jpg, *.jpeg)\r\n"
                                                                   "XML-files (*.xml)")));
  }
  ptr = std::make_unique<File>();
  ptr->SetPath(ui->DirectoryLineEdit->text());
}

void MainWindow::on_PrintPushButton_clicked()
{
  ui->ContentTextEdit->clear();
  ui->ContentTextEdit->setText(ptr->Print());
}

MainWindow::~MainWindow()
{
  delete ui;
}
