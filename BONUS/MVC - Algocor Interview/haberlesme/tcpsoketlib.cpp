#include "tcpsoketlib.h"

// QT Libs
#include <QDebug>
#include <QJsonDocument>
#include <QByteArray>
#include <QTimer>

TcpSoketLib::TcpSoketLib(const QString &adr_, int port_, QObject *parent)
    : QObject{parent} ,
    mAdr{ adr_},
    mPort{ port_}
{
    connect(&mSocket, &QTcpSocket::readyRead, this, &TcpSoketLib::onReadyRead);
    connect(&mSocket, &QTcpSocket::disconnected, this, &TcpSoketLib::onDisconnected);
}

void TcpSoketLib::onReadyRead()
{
    QByteArray data = mSocket.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isNull() && doc.isObject()) {
        emit VeriAlindi(doc);

    } else {
        qDebug() << "Invalid JSON received";
    }
}

void TcpSoketLib::onConnect()
{
    mSocket.connectToHost(mAdr, mPort);

    // Baglanti kurulamazsa 5 sn sonra tekrar baglanti kurulmaya calisir.
    if (mSocket.waitForConnected(5)) {
        m_baglantiDurum = true;
        qDebug() << "Baglanti BASARILI. ";

    } else {
        qDebug() << "Baglanti BASARISIZ. Yeniden deniyor. ";

        QTimer::singleShot(5000, [=]() {
            mSocket.close();
            onConnect();
        });
    }
}

void TcpSoketLib::onDisconnected()
{
    qDebug() << "Soket baglantisi koptu. Yeniden baglanti deniyor.  ";

    m_baglantiDurum = false;
}
