#ifndef FILEDIRCLASS_H
#define FILEDIRCLASS_H
#include <QFileDialog>
#include <QDebug>

enum class SelectionMode
{
  Static = 1,
  Custom = 2
};

class PrintableWithPath
{
public:
  virtual void SetPath(QString path) = 0;
  virtual QString Print() = 0;
  virtual ~PrintableWithPath() = default;
};

class File : public PrintableWithPath
{
  QFile file_;

public:
  void SetPath(QString filePath) override;
  QString Print() override;
};

class Directory : public PrintableWithPath
{
  QDir directory_;

public:
  void SetPath(QString directoryPath) override;
  QString Print() override;
};

#endif  // FILEDIRCLASS_H
