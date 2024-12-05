#include "title_bar.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include "title_btn.h"

TitleBar::TitleBar(QWidget *parent) : QWidget(parent){
    setWindowFlag(Qt::FramelessWindowHint);
    setFixedHeight(sz::title_bar_h);
    setFocusPolicy(Qt::StrongFocus);

    QStringList path_list_btn_min;
    path_list_btn_min << ":/Icons/MainWindow/min.png";
    m_btn_min = new TitleBtn(std::move(path_list_btn_min));
    QStringList path_list_btn_max;
    path_list_btn_max << ":/Icons/MainWindow/max.png";
    m_btn_max = new TitleBtn(std::move(path_list_btn_max));
    QStringList path_list_btn_close;
    path_list_btn_close << ":/Icons/MainWindow/close.png";
    m_btn_close = new TitleBtn(std::move(path_list_btn_close));

    m_btn_min->setToolTip("Minimize");
    m_btn_max->setToolTip("Maximize");
    m_btn_close->setToolTip("Close");

    QHBoxLayout *layout_main = new QHBoxLayout(this);
    layout_main->setSpacing(5);
    layout_main->setContentsMargins(0, 0, 0, 0);
    layout_main->setAlignment(Qt::AlignRight | Qt::AlignTop);
    layout_main->addWidget(m_btn_min);
    layout_main->addWidget(m_btn_max);
    layout_main->addWidget(m_btn_close);

    connect(m_btn_min, &TitleBtn::clicked, this, &TitleBar::onClicked);
    connect(m_btn_max, &TitleBtn::clicked, this, &TitleBar::onClicked);
    connect(m_btn_close, &TitleBtn::clicked, this, &TitleBar::onClicked);
}

void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QMainWindow *mainWindow = qobject_cast<QMainWindow *>(pButton->parent()->parent()->parent());
    // QWidget *pWindow = this->window();
    // qDebug() << pWindow;
    // qDebug() << "Parent type:" << mainWindow->metaObject()->className();
    if (mainWindow->isTopLevel())
    {
        if (pButton == m_btn_min){
            mainWindow->showMinimized();
        }else if (pButton == m_btn_max){
            if(mainWindow->isMaximized()){
                mainWindow->showNormal();//还原
                m_btn_max->setIcon(QPixmap(":/Icons/MainWindow/max.png").
                                scaled(15,15,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
            }else{
                mainWindow->showMaximized();//最大化
                m_btn_max->setIcon(QPixmap(":/Icons/MainWindow/back.png").
                                scaled(15,15,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
            }
        }else if (pButton == m_btn_close){
            mainWindow->close();
        }
    }
}