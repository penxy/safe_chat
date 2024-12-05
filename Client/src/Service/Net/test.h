#pragma once

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>


/**
 * @class HttpClient
 * @brief 这个是测试用的
 */
class HttpClient : public QObject {
    Q_OBJECT
public:
    HttpClient();
private slots:
    void onFinished(QNetworkReply *reply);
private:
    QNetworkAccessManager *manager;
};