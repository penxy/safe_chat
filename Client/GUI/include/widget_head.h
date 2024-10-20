#ifndef WIDGETHEAD_H
#define WIDGETHEAD_H

#include <QWidget>
#include <QPushButton>

class WidgetHead : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetHead(QWidget *parent = nullptr);
public slots:
    void CloseWidget();
    void ResizeWidget();
private:
    void InitUi();
private:
    QPushButton *m_btn_close;
    QPushButton *m_btn_size;
    bool isMax;
};

#endif // WIDGETHEAD_H
