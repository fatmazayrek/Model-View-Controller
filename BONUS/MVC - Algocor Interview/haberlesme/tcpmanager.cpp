#include "tcpmanager.h"

// QT Libs
#include <QJsonDocument>
#include <QJsonObject>

TcpManager::TcpManager(QObject *parent)
    : QObject{parent}
{
}

void TcpManager::onStrategyVerisiAlindi(const QVariant &icerik)
{
    QJsonObject jsonObj = icerik.toJsonDocument().object();

    StrategyUpdate strategyUpdate;
    strategyUpdate.strategyId = jsonObj["strategyId"].toInt();
    strategyUpdate.type = StrToTypeEnum(jsonObj["type"].toString());
    strategyUpdate.name = jsonObj["name"].toString().toStdString();
    strategyUpdate.state = StrToStateEnum(jsonObj["state"].toString());

    emit UpdateStrategy(QVariant::fromValue(strategyUpdate));
}

void TcpManager::onOrderVerisiAlindi(const QVariant &icerik)
{
    QJsonObject jsonObj = icerik.toJsonDocument().object();

    OrderUpdate orderUpdate;
    orderUpdate.orderId = jsonObj["orderId"].toInt();
    orderUpdate.strategyId = jsonObj["strategyId"].toInt();
    orderUpdate.price = jsonObj["price"].toDouble();
    orderUpdate.active_volume = jsonObj["active_volume"].toDouble();
    orderUpdate.filled_volume = jsonObj["filled_volume"].toDouble();
    orderUpdate.side = StrToSideEnum(jsonObj["side"].toString());

    emit UpdateOrders(QVariant::fromValue(orderUpdate));
}

Type TcpManager::StrToTypeEnum(const QString &str)
{
    Type type = Type::StrategyType1;

    if (str == "StrategyType1") {
        type = Type::StrategyType1;

    } else if (str == "StrategyType2") {
        type = Type::StrategyType2;
    }

    return type;
}

State TcpManager::StrToStateEnum(const QString &str)
{
    State state = State::Paused;

    if (str == "Paused") {
        state = State::Paused;

    } else if (str == "Running") {
        state = State::Running;
    }

    return state;
}

Side TcpManager::StrToSideEnum(const QString &str)
{
    Side side = Side::Buy;

    if (str == "Buy") {
        side = Side::Buy;

    } else if (str == "Sell") {
        side = Side::Sell;
    }

    return side;
}
