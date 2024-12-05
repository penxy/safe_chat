#include "rmchatdialog.h"
#include <QPushButton>

RmChatDialog::RmChatDialog(QWidget* parent) : QDialog(parent){
    ui.setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setAttribute(Qt::WA_QuitOnClose, false);

    // QString str_name = "张三";
    // QString name = str_name.toHtmlEscaped();
    QString text = tr("Are you sure you want to remove %1 from your contacts list?")
                    .arg(QString("<b>%1</b>").arg("name"));

    ui.label->setText(text);
    auto removeButton = ui.buttonBox->button(QDialogButtonBox::Ok);
    auto cancelButton = ui.buttonBox->button(QDialogButtonBox::Cancel);
    removeButton->setText(tr("Remove"));
    cancelButton->setDefault(true);
    adjustSize();
    connect(ui.buttonBox, &QDialogButtonBox::accepted, [this](){emit SigRmChatAgree();});
    connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &RmChatDialog::close);
    setFocus();
}