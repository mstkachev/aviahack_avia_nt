#ifndef MYIMAGESTORE_H
#define MYIMAGESTORE_H

#include <QObject>
#include <QList>
#include <QFileDialog>
#include <QGuiApplication>
#include <QImage>
#include <QImageReader>
#include <QImageWriter>
#include <QStandardPaths>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QColorSpace>
#include "ImageProcessing/myimageobject.h"




class MyImageStore:public QObject
{
    Q_OBJECT
public:
    MyImageStore(QWidget *a_ui,QLabel *a_ImageViewer):_ui(a_ui),_ImageViewer(a_ImageViewer){};
    // Функция добавления в массив нового изображения
    void AddImagefromFileDialog();
private:
    // Хранилище данных
    QList<MyImageObject*> _ImageData;
    //
    QWidget * _ui;

    QLabel * _ImageViewer;
    //static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode);
    bool loadFile(const QString &fileName);


    static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
    {
        static bool firstDialog = true;

        if (firstDialog) {
            firstDialog = false;
            const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
            dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
        }

        QStringList mimeTypeFilters;
        const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
            ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
        for (const QByteArray &mimeTypeName : supportedMimeTypes)
            mimeTypeFilters.append(mimeTypeName);
        mimeTypeFilters.sort();
        dialog.setMimeTypeFilters(mimeTypeFilters);
        dialog.selectMimeTypeFilter("image/jpeg");
        if (acceptMode == QFileDialog::AcceptSave)
            dialog.setDefaultSuffix("jpg");
    }

};

#endif // MYIMAGESTORE_H
