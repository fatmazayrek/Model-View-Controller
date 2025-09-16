#ifndef TCPSOKETLIB_H
#define TCPSOKETLIB_H

// QT Libs
#include <QObject>
#include <QTcpSocket>

/*!
 * \brief The TcpSoketLib class
 * TCP baglantisini saglar.
 * Veri gonderme/alma islemleri burada gerceklesir
 */
class TcpSoketLib : public QObject
{
    Q_OBJECT
public:
    explicit TcpSoketLib(const QString &adr_,
                         int port_,
                         QObject *parent = nullptr);

signals:
    void VeriAlindi(const QVariant &icerik);

public slots:
    /*!
     * \brief onReadyRead
     * Soket nesnesinden veri okunmasini saglar
     */
    void onReadyRead();

    /*!
     * \brief onConnect
     * Soket baglantisi kurar
     */
    void onConnect();

    /*!
     * \brief onDisconnected
     * Soket baglantisi koptugunda yeniden baglanti kurmayi dener
     */
    void onDisconnected();

private:
    QTcpSocket mSocket;

    const QString mAdr = "";
    const int mPort = -1;
    bool m_baglantiDurum = false;
};

#endif // TCPSOKETLIB_H
