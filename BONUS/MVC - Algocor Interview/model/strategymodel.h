#ifndef STRATEGYMODEL_H
#define STRATEGYMODEL_H

// QT Libs
#include <QObject>
#include <QAbstractListModel>

// INNER Class
#include "mesajlar.h"

class StrategyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StrategyModel(QObject *parent = nullptr);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        TypeRole,
        NameRole,
        StateRole
    };

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    StrategyUpdate clickedStrategy(int id);

public:
    void onUpdateStrategy(const QVariant &icerik);

private:
    QVector<StrategyUpdate> mStrategies;
    StrategyUpdate mClickedStrategy;
};

#endif // STRATEGYMODEL_H
