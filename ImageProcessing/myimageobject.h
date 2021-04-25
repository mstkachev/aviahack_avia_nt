#ifndef MYIMAGEOBJECT_H
#define MYIMAGEOBJECT_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QFile>
class MyImageObject
{
public:
    MyImageObject(const QString & a_ImageFileName):_ImageFileName(a_ImageFileName)
    {


    };

    QImage _image;
private:
    // наименование файла.
    QString _ImageFileName;
    // Сам файл
    QFile *_ImageFile;
};

#endif // MYIMAGEOBJECT_H
