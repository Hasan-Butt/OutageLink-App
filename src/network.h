#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>
#include "data.h"
#include <QList>
#include <functional>


class NetworkClient : public QObject {
    Q_OBJECT
public:
    explicit NetworkClient(const QString& baseUrl, QObject* parent = nullptr);

    // Fetch the full lists
    void fetchReports();
    void fetchResources();
    void fetchRequests();
    void fetchAnnouncements();

    // Post new items
    void postReport(const Report&);
    void postResource(const Resource&);
    void postRequest(const Request&);
    void postAnnouncement(const Announcement&);

signals:
    void reportsFetched(const QList<Report>&);
    void resourcesFetched(const QList<Resource>&);
    void requestsFetched(const QList<Request>&);
    void announcementsFetched(const QList<Announcement>&);
    void networkError(const QString& err);

private:
    QNetworkAccessManager  mgr;
    QString                m_baseUrl;

    template<typename T>
    void handleFetchReply(QNetworkReply* reply,
                          std::function<T(const QJsonObject&)> ctor,
                          std::function<void(const QList<T>&)> callback)
    {
        if (reply->error()) {
            emit networkError(reply->errorString());
        } else {
            QJsonArray arr = QJsonDocument::fromJson(reply->readAll()).array();
            QList<T> list;
            for (auto val : arr)
                list.append(ctor(val.toObject()));
            callback(list);
        }
        reply->deleteLater();
    }

    template<typename T>
    void postItem(const QString& path,
                  const T& item,
                  std::function<QJsonObject()> toJson)
    {
        QNetworkRequest req(QUrl(m_baseUrl + "/api/" + path));
        req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        auto* reply = mgr.post(req,
                               QJsonDocument(toJson()).toJson());
        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error())
                emit networkError(reply->errorString());
            reply->deleteLater();
        });
    }
};

#endif // NETWORK_H
