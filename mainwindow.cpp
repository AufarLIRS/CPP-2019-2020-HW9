#include "mainwindow.h"
#include "ui_mainwindow.h"

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
  if (ui->allFilesRadioButton->isChecked())
  {
    ui->pathLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "C:/", tr("All (*.*);;")));
  }
  else if (ui->readableAsDocRadioButton->isChecked())
  {
    ui->pathLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "C:/",
                                                           tr("All (*.*);;"
                                                              "Documents (*.doc *.docx *.pdf);;"
                                                              "Text files (*.txt);;"
                                                              "XML files (*.xml)")));
  }
  ptr = std::make_unique<getFile>();
}

void MainWindow::on_selectFolderPushButton_clicked()
{
  ui->pathLineEdit->setText(QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
  ptr = std::make_unique<Folder>();
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
