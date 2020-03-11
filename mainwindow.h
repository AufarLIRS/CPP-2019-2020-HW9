#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "file.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_selectFilePushButton_clicked();

  void on_selectFolderPushButton_clicked();

  void on_Print_clicked();

private:
  Ui::MainWindow* ui;
  std::unique_ptr<IPrintablePath> ptr;
};
#endif  // MAINWINDOW_H
