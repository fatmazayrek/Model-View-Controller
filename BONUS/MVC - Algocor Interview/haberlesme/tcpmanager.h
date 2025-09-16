#ifndef TCPMANAGER_H
#define TCPMANAGER_H

// QT Libs
#include <QObject>

// INNER Class
#include "model/mesajlar.h"

class TcpManager : public QObject
{
    Q_OBJECT
public:
    explicit TcpManager(QObject *parent = nullptr);

signals:
    void UpdateStrategy(const QVariant &icerik);
    void UpdateOrders(const QVariant &icerik);

public slots:
    void onStrategyVerisiAlindi(const QVariant &icerik);
    void onOrderVerisiAlindi(const QVariant &icerik);

private:
    Type StrToTypeEnum(const QString &str);
    State StrToStateEnum(const QString &str);
    Side StrToSideEnum(const QString &str);
};

#endif // TCPMANAGER_H
