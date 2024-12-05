#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <memory>
class Core;

/**
 * @class FtpPage
 * @brief 上传、下载文件界面
 * @todo 需要完善，比如进度条，逻辑判断
 */
class FtpPage : public QWidget{
    Q_OBJECT
public:
    FtpPage(std::shared_ptr<Core>core, QWidget *parent = nullptr);
    // ~FtpPage();
// signals:
//     void SigFileUp(const QString& file_name);
private:
    std::shared_ptr<Core>m_core;

    QLineEdit m_line_file_up;
    QPushButton m_btn_file_up;
    QLineEdit m_line_file_down;
    QPushButton m_btn_file_down;

    QProgressBar m_process;
    QLabel m_lab_speed;
    QLabel m_lab_unit;
};
