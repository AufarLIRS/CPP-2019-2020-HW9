#include "filedirclass.h"

void File::SetPath(QString filePath)
{
  file_.setFileName(filePath);
}

void Directory::SetPath(QString directoryPath)
{
  directory_.setPath(directoryPath);
}

QString File::Print()
{
  file_.open(QIODevice::ReadOnly);
  if (file_.isOpen())
  {
    auto text = new QTextStream(&file_);
    return text->readAll();
  }
  else
  {
    return "Reading error";
  }
}

QString Directory::Print()
{
  directory_.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
  auto str = directory_.entryInfoList();
  QString text = "";
  for (auto s : str)
  {
    text = text + s.filePath() + "\r\n";
  }
  return text;
}
