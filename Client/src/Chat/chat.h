#pragma once

#include <QObject>
#include <QPixmap>
#include <QDateTime>
#include "chatid.h"
#include "utils/interface.h"
#include "config.h"

/**
 * @class Chat
 * @brief Friend和Group的基类, 定义了一些基本的接口和信号
 */
class Chat : public QObject
{
    Q_OBJECT
public:
    virtual ~Chat() = 0;

    virtual void setName(const QString& name) = 0;
    virtual QString& getName() = 0;

    //因为ID不会被改变，所以只提供get方法
    virtual ChatId& getId() = 0;

    virtual void setPix(const QPixmap& pix) = 0;
    virtual QPixmap& getPix() = 0;

    virtual QList<ns::History>& getHistory() = 0;
    virtual void setHistory(const QList<ns::History>& history) = 0;

    DECLARE_SIGNAL(SigNameChanged, const QString&);
    DECLARE_SIGNAL(SigPixChanged, const QPixmap&);
};
