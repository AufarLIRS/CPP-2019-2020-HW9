#include "file.h"

void File::setPath(QString path)
{
  file_.setFileName(path);
}

QString File::print()
{
  file_.open(QIODevice::ReadOnly);
  QTextStream text(&file_);
  return text.readAll();
}

void Folder::setPath(QString path)
{
  directory_.setPath(path);
}

QString Folder::print()
{
  directory_.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
  QString str;
  auto list = directory_.entryInfoList();
  for (auto s : list)
  {
    str.append(s.filePath() + "\r\n");
  }
  return str;
}
