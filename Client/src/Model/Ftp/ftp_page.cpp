#include "ftp_page.h"
#include <QHBoxLayout>
#include "Core/core.h"

static const QSize ftp_btn = QSize(60, 40);
static const int ftp_line_h = 40;

FtpPage::FtpPage(std::shared_ptr<Core>core, QWidget *parent) : QWidget(parent), m_core(core){
    m_btn_file_up.setText("up");
    m_btn_file_down.setText("down");

    //test
    // m_line_file_up.setText("/home/pxy/work/safe_chat/s.py");
    // m_line_file_down.setText("/home/pxy/work/safe_chat/temp_1");

    QHBoxLayout *layout_up = new QHBoxLayout;
    layout_up->addWidget(&m_line_file_up);
    layout_up->addWidget(&m_btn_file_up);

    QHBoxLayout *layout_down = new QHBoxLayout;
    layout_down->addWidget(&m_line_file_down);
    layout_down->addWidget(&m_btn_file_down);

    // QHBoxLayout *layout_bar = new QHBoxLayout;
    // layout_bar->addWidget(&m_process);
    // layout_bar->addWidget(&m_lab_speed);
    // layout_bar->addWidget(&m_lab_unit);

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    layout_main->setSpacing(5);
    layout_main->addLayout(layout_up);
    layout_main->addLayout(layout_down);
    // layout_main->addLayout(layout_bar);
    layout_main->setAlignment(Qt::AlignTop);

    connect(&m_btn_file_up, &QPushButton::clicked, [this](){
        m_core->upLoadFile(m_line_file_up.text());
    });
    connect(&m_btn_file_down, &QPushButton::clicked, [this](){
        m_core->downLoadFile(m_line_file_down.text());
    });
}

// FtpPage::~FtpPage(){
    
// }