#ifndef FILE_H
#define FILE_H

#include <QFileDialog>
#include <QDebug>

class IPrintable
{
public:
    virtual ~IPrintable() = default;
    virtual QString print() = 0;
};

class IAvailablePath
{
public:
    virtual ~IAvailablePath() = default;
    virtual void setPath(QString path) = 0;
};

class IPrintablePath : public IPrintable, public IAvailablePath
{

};

class File : public IPrintablePath
{
    QFile file_;

public:
    void setPath(QString path) override;
    QString print() override;
};

class Folder : public IPrintablePath
{
    QDir directory_;

public:
    void setPath(QString path) override;
    QString print() override;
};

#endif // FILE_H
