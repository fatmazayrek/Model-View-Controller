#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

// QT Libs
#include <QObject>
#include <QSharedPointer>

// INNER Class
#include "model/strategymodel.h"
#include "model/ordermodel.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    Q_PROPERTY(QAbstractListModel* strategyModel READ strategyModel CONSTANT FINAL)
    Q_PROPERTY(QAbstractListModel* orderModel READ orderModel CONSTANT FINAL)
    Q_PROPERTY(int clickedStrategyId READ clickedStrategyId WRITE setClickedStrategyId NOTIFY clickedStrategyIdChanged FINAL)
    Q_PROPERTY(QString strategyType READ strategyType NOTIFY strategyChanged FINAL)
    Q_PROPERTY(QString strategyName READ strategyName NOTIFY strategyChanged FINAL)
    Q_PROPERTY(QString strategyState READ strategyState NOTIFY strategyChanged FINAL)

    Q_INVOKABLE void strategyClicked(int id);

signals:
    void clickedStrategyIdChanged();
    void strategyChanged();

public:
    QAbstractListModel *strategyModel() const;
    QAbstractListModel *orderModel() const;
    int clickedStrategyId() const;

    QString strategyType() const;
    QString strategyName() const;
    QString strategyState() const;

    void setClickedStrategyId(int newClickedStrategyId);

public slots:
    void onUpdateStrategy(const QVariant &icerik);
    void onUpdateOrder(const QVariant &icerik);

private:
    QSharedPointer<StrategyModel> m_strategyModel;
    QSharedPointer<OrderModel> m_orderModel;

    int m_clickedStrategyId;
    QString m_strategyType;
    QString m_strategyName;
    QString m_strategyState;
};

#endif // MAINCONTROLLER_H
