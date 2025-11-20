#ifndef WORKER_H
#define WORKER_H
#include <QUdpSocket>
#include <QDebug>
#include <QObject>
#include <QHostAddress>
#include <QNetworkDatagram>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
public slots:
    void sendMessage(uint16_t message);
    void recieveMessage();
    void init();
private:
    QUdpSocket *socket;
};

#endif // WORKER_H
