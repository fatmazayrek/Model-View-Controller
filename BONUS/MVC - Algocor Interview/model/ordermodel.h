#ifndef ORDERMODEL_H
#define ORDERMODEL_H

// QT Libs
#include <QObject>
#include <QAbstractListModel>

// INNER Class
#include "mesajlar.h"

class OrderModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit OrderModel(QObject *parent = nullptr);

    enum Roles {
        OrderIdRole = Qt::UserRole + 1,
        StrategyIdRole,
        PriceRole,
        ActiveVolumeRole,
        FilledVolumeRole,
        SideRole
    };

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    void onUpdateOrder(const QVariant &icerik);
    void setClickedStrategy(int strategyId);                // -1 ise secili strategy yok demek

private:
    QVector<OrderUpdate> mAllOrders;
    QVector<OrderUpdate> MSeciliOrders;
    int mClickedStrageyId = -1;

private:
    void updateSeciliOrders();

};

#endif // ORDERMODEL_H
