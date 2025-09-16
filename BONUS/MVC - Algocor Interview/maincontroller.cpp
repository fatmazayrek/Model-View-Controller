#include "maincontroller.h"

#include <iostream>

MainController::MainController(QObject *parent)
    : QObject{parent} ,
    m_strategyModel{ new StrategyModel },
    m_orderModel{ new OrderModel },
    m_clickedStrategyId{ -1}
{}

void MainController::strategyClicked(int id)
{
    setClickedStrategyId(id);

    m_orderModel->setClickedStrategy(id);
    emit strategyChanged();
}

QAbstractListModel *MainController::strategyModel() const
{
    return m_strategyModel.get();
}

QAbstractListModel *MainController::orderModel() const
{
    return m_orderModel.get();
}

int MainController::clickedStrategyId() const
{
    return m_clickedStrategyId;
}

QString MainController::strategyType() const
{
    QString str = " - ";
    if (m_clickedStrategyId > 0) {
        str = Type2StdString(m_strategyModel->clickedStrategy(m_clickedStrategyId).type);
    }

    return str;
}

QString MainController::strategyName() const
{
    QString str = " - ";
    if (m_clickedStrategyId > 0) {
        str = QString::fromStdString(m_strategyModel->clickedStrategy(m_clickedStrategyId).name);
    }

    return str;
}

QString MainController::strategyState() const
{
    QString str = " - ";
    if (m_clickedStrategyId > 0) {
        str = State2StdString(m_strategyModel->clickedStrategy(m_clickedStrategyId).state);
    }

    return str;
}

void MainController::setClickedStrategyId(int newClickedStrategyId)
{
    if (m_clickedStrategyId == newClickedStrategyId)
        return;
    m_clickedStrategyId = newClickedStrategyId;
    emit clickedStrategyIdChanged();
}

void MainController::onUpdateStrategy(const QVariant &icerik)
{
    m_strategyModel->onUpdateStrategy(icerik);
}

void MainController::onUpdateOrder(const QVariant &icerik)
{
    m_orderModel->onUpdateOrder(icerik);
}
