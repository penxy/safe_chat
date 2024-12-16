#pragma once

#include "single_model.h"

class Tool : public Singleton<Tool> {
    friend class Singleton<Tool>;
public:
    Tool (const Tool&) = delete;
    Tool& operator = (const Tool&) = delete;
protected:
    Tool() = default;
public: 
    enum class TypeQss{
        ComBox,
        Label,
        TextEdit,
    };
    QString pix2Base64(const QPixmap &pixmap);
    QPixmap base642Pix(const QString &base64);
    QString getQss(TypeQss type);
    bool replace(std::string& str, const std::string& from, const std::string& to);
    void ConvertPath(std::string& str);
    void ConvertPath(QString& str);
};

#define TOOL Tool::get_inst()