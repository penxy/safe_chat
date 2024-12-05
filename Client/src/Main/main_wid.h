#pragma

#include "Base/wid_base.h"
#include <QMouseEvent>
#include "widget.h"

/**
 * @class MainWid
 * @brief 展示的主窗口，用于显示Widget
 */
class MainWid : public WidBase{
    Q_OBJECT
public:
    explicit MainWid(QMainWindow *parent = 0);
private:
    Widget m_main_wid;
};
