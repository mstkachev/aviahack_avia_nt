#include "myimagestore.h"




// Import
void MyImageStore::AddImagefromFileDialog()
{

    QFileDialog dialog(_ui, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}

}



bool MyImageStore::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(_ui, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
}

    _ImageData.append(new MyImageObject(fileName));

    _ImageData.back()->_image = newImage;

    _ui->setWindowFilePath(fileName);



    // пишем эту хуйнюв  лейбл.
QImage newImage2 = newImage;
    if (_ImageData.back()->_image.colorSpace().isValid())
       _ImageData.back()->_image.convertToColorSpace(QColorSpace::SRgb);



    _ImageViewer->setPixmap(QPixmap::fromImage(newImage));


    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
       .arg(QDir::toNativeSeparators(fileName)).arg(_ImageData.back()->_image.width()).arg(_ImageData.back()->_image.height()).arg(_ImageData.back()->_image.depth());

    _ui->setStatusTip(message);

    return true;
 }


