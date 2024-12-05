#pragma once

#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    HTTPManager(QObject *parent = nullptr);
    ~HTTPManager();
    void postData(QString str);
    void getData();
private Q_SLOTS:
    void replyFinished(QNetworkReply *rep);
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
};