#include "ordermodel.h"

OrderModel::OrderModel(QObject *parent) : QAbstractListModel{parent} {}

int OrderModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return MSeciliOrders.size();
}

QVariant OrderModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= MSeciliOrders.size())
        return {};

    const OrderUpdate &orderUp = MSeciliOrders.at(index.row());

    switch(role) {
    case OrderIdRole:
        return QVariant::fromValue(orderUp.orderId);
    case StrategyIdRole:
        return QVariant::fromValue(orderUp.strategyId);
    case PriceRole:
        return QVariant::fromValue(orderUp.price);
    case ActiveVolumeRole:
        return QVariant::fromValue(orderUp.active_volume);
    case FilledVolumeRole:
        return QVariant::fromValue(orderUp.filled_volume);
    case SideRole:
        return QVariant::fromValue(Side2StdString(orderUp.side));
    }

    return {};
}

QHash<int, QByteArray> OrderModel::roleNames() const
{
    return {
        {OrderIdRole, "orderId"},
        {StrategyIdRole, "strategyId"},
        {PriceRole, "price"},
        {ActiveVolumeRole, "activeVolume"},
        {FilledVolumeRole, "filledVolume"},
        {SideRole, "side"},
    };
}

void OrderModel::onUpdateOrder(const QVariant &icerik)
{
    OrderUpdate order = icerik.value<OrderUpdate>();

    // Var ise Guncelle yoksa EKLE
    for (int i = 0; i < mAllOrders.size(); ++i) {
        if (mAllOrders[i].orderId == order.orderId) {
            mAllOrders[i] = order;
            updateSeciliOrders();
            return;
        }
    }

    mAllOrders.append(order);
    updateSeciliOrders();
}

void OrderModel::setClickedStrategy(int strategyId)
{
    if (mClickedStrageyId != strategyId) {
        mClickedStrageyId = strategyId;

        updateSeciliOrders();
    }
}

void OrderModel::updateSeciliOrders()
{
    beginResetModel();

    if (mClickedStrageyId < 0) {
        MSeciliOrders = mAllOrders;

    } else {
        MSeciliOrders.clear();

        for (const auto &order : mAllOrders) {
            if (order.strategyId == mClickedStrageyId)
                MSeciliOrders.append(order);
        }
    }

    endResetModel();
}
