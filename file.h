#ifndef FILE_H
#define FILE_H

#include <QFileDialog>
#include <QDebug>

class Printable
{
public:
  virtual ~Printable() = default;
  virtual QString print() = 0;
  virtual void setPath(QString path) = 0;
};

class CustomFile : public Printable
{
  QFile file_;

public:
  CustomFile() = default;
  void setPath(QString path) override;
  QString print() override;
};

class CustomFolder : public Printable
{
  QDir folder_;

public:
  CustomFolder() = default;
  void setPath(QString path) override;
  QString print() override;
};
#endif  // FILE_H
