#include <QBuffer>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <algorithm>
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
    std::string path_qss;
    switch (type) {
        case TypeQss::ComBox:{
            path_qss = "/etc/Qss/ComBox.qss";
            break;
        }
        case TypeQss::Label:{
            path_qss = "/etc/Qss/QLabel.qss";
            break;
        }
        case TypeQss::TextEdit:{
            path_qss = "/etc/Qss/QTextEdit.qss";
            break;
        }
        default:
            break;
    }

    Tool::ConvertPath(path_qss);
    file = FLAGS_base + path_qss;
    QFile fileQss(file.c_str());
    if(fileQss.open(QIODevice::ReadOnly)){
        return QString::fromStdString(fileQss.readAll().toStdString());
    }else{
        qDebug() << QString("file %1 open fail").arg(file.c_str());
    }
    return QString();
}

bool Tool::replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return Tool::replace(str, from, to);
}

/**
 * @def ConvertPath
 * @brief 将Linux路径转为Windows路径
 */
void Tool::ConvertPath(std::string& str){
#ifdef _WIN32
    Tool::replace(str, "/", "\\");
#endif
}

void Tool::ConvertPath(QString& str){
#ifdef _WIN32
    std::string temp = str.toStdString();
    Tool::ConvertPath(temp);
    str = QString::fromStdString(temp);
#endif
}