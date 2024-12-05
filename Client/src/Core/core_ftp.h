#pragma once
#include <QString>

class CoreFtp{
public:
    CoreFtp() = default;
    ~CoreFtp() = default;
    CoreFtp(const CoreFtp&) = default;
    CoreFtp& operator=(const CoreFtp&) = default;
    CoreFtp(CoreFtp&&) = default;
    CoreFtp& operator=(CoreFtp&&) = default;

    virtual void upLoadFile(const QString& file_name) = 0;
    virtual void downLoadFile(const QString& file_name) = 0;
};