#pragma once
#ifdef __USE_GFLAGS__
#include "gflags/gflags.h"
DECLARE_string(base);
#else
#include <string>
#include <QCommandLineParser>

extern QCommandLineParser parser;//有一些玄学问题，暂时只能这样写
#define FLAGS_base parser.value("b").toStdString()

#endif
