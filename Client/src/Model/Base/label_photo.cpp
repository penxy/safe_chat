#include "label_photo.h"

LabelPhoto::LabelPhoto(QWidget *parent) : QLabel(parent){
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QString qss = QString(R"(
        QLabel {
            border: 2px solid #8f8f91;
        }
    )");
    setStyleSheet(qss);
}

void LabelPhoto::SetPhoto(const QPixmap& pixmap){
    //pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setPixmap(pixmap);
}