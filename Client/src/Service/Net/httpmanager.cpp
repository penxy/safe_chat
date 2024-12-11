#include "httpmanager.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>

HTTPManager::HTTPManager(QObject *parent)
    : QObject(parent), m_manager(new QNetworkAccessManager(this)), m_timer(new QTimer(this)), m_loop(new QEventLoop(this))
{
    connect(m_manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    connect(m_timer, SIGNAL(timeout()), m_loop, SLOT(quit()));                                             //超时退出
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), m_loop, SLOT(quit()));                            //收到退出

    QNetworkRequest request;
    QUrl url;
    url.setScheme("http");
    url.setHost("www.baidu.com");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);
    m_manager->get(request);

    m_timer->start(3000);
    m_loop->exec();
}

HTTPManager::~HTTPManager()
{
}

void HTTPManager::postData(QString str)
{
    QNetworkRequest request;
    QByteArray data = str.toUtf8();

    QUrl url;

    url.setScheme("http");
    url.setHost("www.baidu.com");
    //url.setPath("/node/filter_data");
    request.setUrl(url);
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    m_manager->post(request, data);
    // manager->get(request);
}

void HTTPManager::replyFinished(QNetworkReply *rep)
{
    if(rep->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error: " << rep->errorString();
        return;
    }
    QByteArray bts = rep->readAll();
    qDebug() << QString::fromStdString(bts.toStdString());

    QString str = QString::fromUtf8(bts);
    qDebug().noquote() << "Reply:"<< str;
    qDebug() << str;
    rep->deleteLater();
}