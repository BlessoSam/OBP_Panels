#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}


void Worker::init()
{
    socket = new QUdpSocket(this);
    bool ok = socket->bind(QHostAddress::Any,8080);
    if(!ok) qDebug()<<"Unable to bind"<<socket->errorString(); return;

    // if(!socket->joinMulticastGroup(groupIP)) qDebug()<<"Unable to join Multicast"<<socket->errorString(); return;

    connect(socket,&QUdpSocket::readyRead,this,&Worker::recieveMessage);
}



void Worker::sendMessage(uint16_t message)
{
    QByteArray data;
    QHostAddress groupIP("127.0.0.1");
    quint16 port = 4023;
    QDataStream stream(&data,QIODevice::WriteOnly);
    stream<<(quint16)message;

    qint64 bytes = socket->writeDatagram(data,groupIP, 4023);
    qDebug() << "Bytes sent =" << bytes << "Error =" << socket->errorString();

    qDebug()<<"Data sent:"<<data.toHex()<<"to group "<<groupIP<<port;
}

void Worker::recieveMessage()
{
    while(socket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 port;
        socket->readDatagram(datagram.data(),datagram.size(),&sender,&port);
        qDebug()<<"Data Recieved: "<<datagram.data()<<" From "<<sender.toString()<<port;
    }
}

