#pragma once

#include <QTimer>
#include <memory>
#include "Setting/isystem_setting.h"
#include <QVariant>

/**
 * @class Setting
 * @brief parse json setting file and have time out to save setting file
 * @note 也许存在信号？
 */
class Setting : public QObject,
                public ISystemSetting,
                public std::enable_shared_from_this<Setting> {
    Q_OBJECT
public:
    Setting();
    ~Setting();

    //ISystemSetting interface
    QString& getUser() override;
    QString& getPassword() override;
    QString& getIpFtp() override;
    QString& getKey() override;
    QString& getIv() override;
    QString& getDb() override;
};