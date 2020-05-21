#include "file.h"

void CustomFile::setPath(QString path)
{
  file_.setFileName(path);
}

QString CustomFile::print()
{
  file_.open(QIODevice::ReadOnly);
  QTextStream content(&file_);
  return content.readAll();
}

void CustomFolder::setPath(QString path)
{
  folder_.setPath(path);
}

QString CustomFolder::print()
{
  QString listing = "";
  auto list = folder_.entryList();
  for (auto i = list.begin(); i < list.end(); i++)
    listing = listing + *i + " ";

  return listing;
}
