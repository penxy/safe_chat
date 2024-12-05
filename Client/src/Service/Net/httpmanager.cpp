#include "httpmanager.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

HTTPManager::HTTPManager(QObject *parent)
    : QObject(parent), manager(new QNetworkAccessManager(this))
{
    connect(manager, &QNetworkAccessManager::finished,this, &HTTPManager::replyFinished);
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
    manager->post(request, data);
    // manager->get(request);
}

void HTTPManager::getData(){
    QNetworkRequest request;
    QUrl url;

    //url.setScheme("http");
    url.setHost("www.baidu.com");
    request.setUrl(url);
    manager->get(request);
}

void HTTPManager::replyFinished(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    qDebug() << QString::fromStdString(bts.toStdString());

    QString str = QString::fromUtf8(bts);
    qDebug().noquote() << "Reply:"<<str;
    qDebug() << str;
    rep->deleteLater();
}