#pragma once

#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;
class QTimer;
class QEventLoop;

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    HTTPManager(QObject *parent = nullptr);
    ~HTTPManager();
    void postData(QString str);
private Q_SLOTS:
    void replyFinished(QNetworkReply *rep);
private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;
    QTimer *m_timer;
    QEventLoop *m_loop;
};