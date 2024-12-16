#include <QApplication>
#include "Main/main_wid.h"
#include <assert.h>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "args.h"
#include <chrono>

QCommandLineParser parser;
#if 1
int main(int argc, char *argv[])  
{
#ifdef __USE_GFLAGS__
    google::ParseCommandLineFlags(&argc, &argv, true);
#endif
    QApplication app(argc, argv);
    QCoreApplication::setApplicationVersion("0.1");
    QCoreApplication::setApplicationName("safe_chat");

    //parse cmdline args
    QCommandLineOption op_base("b");
    op_base.setValueName("value");
    parser.addOption(op_base);
    parser.process(app);
    assert(parser.isSet(op_base));

    auto time_start = std::chrono::system_clock::now();
    //Card wMain(Type::Info::Identity::Friend, std::static_pointer_cast<void>(std::make_shared<ns::FriendInfo>(ns::FriendInfo(1, "22", QPixmap(":/Icons/image.png")))));
    MainWid wMain;
    // printf("use time: %lldms\n", (long long int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - time_start)).count());
    // printf("use time: %lldms\n", (long long int)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_start).count());
    wMain.show();
    return app.exec();
}
#else
#include "Model/Ftp/ftp_page.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FtpPage wMain;
    wMain.show();
    return a.exec();
}
#endif