#pragma once

#include <QTimer>
#include <memory>
#include "Setting/isystem_setting.h"
#include <QVariant>

/**
 * @class CoreSetting
 * @brief parse json setting file and have time out to save setting file
 * @note 也许存在信号？
 */
class CoreSetting : public QObject,
                public ISystemSetting,
                public std::enable_shared_from_this<CoreSetting> {
    Q_OBJECT
public:
    CoreSetting();
    ~CoreSetting();

    //ISystemSetting interface
    QString& getUser() override;
    QString& getPassword() override;
    QString& getIpFtp() override;
    QString& getKey() override;
    QString& getIv() override;
    QString& getDbName() override;
    QString& getDbScript() override;
};