#include "test.h"

HttpClient::HttpClient() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &HttpClient::onFinished);
    QUrl url("http://www.baidu.com");
    manager->get(QNetworkRequest(url));
}


void HttpClient::onFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Response:" << reply->readAll();
        qDebug() << "_---------------------_";
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}