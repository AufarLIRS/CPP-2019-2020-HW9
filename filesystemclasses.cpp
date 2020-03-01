#include "filesystemclasses.h"

void File::SetPath(QString filepath)
{
  _file.setFileName(filepath);
}

QString File::Print()
{
  _file.open(QIODevice::ReadOnly);
  QTextStream text(&_file);
  return text.readAll();
}

void Directory::SetPath(QString dirpath)
{
  _dir.setPath(dirpath);
}

QString Directory::Print()
{
  _dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
  QString str;
  auto list = _dir.entryInfoList();
  for (auto s : list)
  {
    str.append(s.filePath() + "\r\n");
  }
  return str;
}
