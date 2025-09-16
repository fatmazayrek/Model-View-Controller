#include "strategymodel.h"

// STANDARD Libs
#include <iostream>
#include <algorithm>
#include <ranges>

// QT Libs
#include <QThread>

StrategyModel::StrategyModel(QObject *parent) : QAbstractListModel{parent}
{
    mClickedStrategy.strategyId = -1;
}

int StrategyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mStrategies.size();
}

QVariant StrategyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= mStrategies.size())
        return {};

    const StrategyUpdate &st = mStrategies.at(index.row());

    switch(role) {
    case IdRole:
        return QVariant::fromValue(st.strategyId);
    case TypeRole:
        return QVariant::fromValue(Type2StdString(st.type));
    case NameRole:
        return QVariant::fromValue(QString::fromStdString(st.name));
    case StateRole:
        return QVariant::fromValue(State2StdString(st.state));
    }

    return {};
}

QHash<int, QByteArray> StrategyModel::roleNames() const
{
    return {
        {IdRole, "strategyId"},
        {TypeRole, "type"},
        {NameRole, "name"},
        {StateRole, "status"}
    };
}

StrategyUpdate StrategyModel::clickedStrategy(int id)
{
    for (auto st: mStrategies) {
        if (st.strategyId == id) {
            mClickedStrategy = st;
        }
    }

    return mClickedStrategy;
}

void StrategyModel::onUpdateStrategy(const QVariant &icerik)
{
    StrategyUpdate su = icerik.value<StrategyUpdate>();

    // Varsa Guncelle yoksa EKLE
    for (int i = 0; i < mStrategies.size(); ++i) {
        if (mStrategies[i].strategyId == su.strategyId) {
            mStrategies[i] = su;
            emit dataChanged(index(i), index(i));
            return;
        }
    }

    beginInsertRows(QModelIndex(), mStrategies.size() , mStrategies.size());
    mStrategies.append(su);
    endInsertRows();
}
