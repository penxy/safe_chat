#include <QBuffer>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include "tool.h"
#include "args.h"

QString Tool::pix2Base64(const QPixmap &pixmap) {
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    pixmap.save(&buffer, "PNG"); // 保存为PNG格式，也可以选择其他格式

    return QString(byteArray.toBase64());
}
QPixmap Tool::base642Pix(const QString &base64){
    QPixmap image;
    image.loadFromData(QByteArray::fromBase64(base64.toLocal8Bit()));
    return image;
}

QString Tool::getQss(TypeQss type){
    std::string file;
    switch (type) {
        case ComBox:{
            file = FLAGS_base + "/etc/Qss/ComBox.qss";
            break;
        }
        case Label:{
            file = FLAGS_base + "/etc/Qss/QLabel.qss";
            break;
        }
        case TextEdit:{
            file = FLAGS_base + "/etc/Qss/QTextEdit.qss";
            break;
        }
        default:
            break;
    }
    QFile fileQss(file.c_str());
    if(fileQss.open(QIODevice::ReadOnly)){
        return QString::fromStdString(fileQss.readAll().toStdString());
    }else{
        qDebug() << QString("file %1 open fail").arg(file.c_str());
    }
    return QString();
}

