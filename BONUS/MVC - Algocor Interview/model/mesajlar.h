#ifndef MESAJLAR_H
#define MESAJLAR_H

// QT Libs
#include <QMetaType>

enum class Type
{
    StrategyType1,
    StrategyType2
};

inline QString Type2StdString(Type type)
{
    switch (type) {
        case Type::StrategyType1: return "StrategyType1";
        case Type::StrategyType2: return "StrategyType2";
        default: return "-";
    }
}

enum class State
{
    Paused,
    Running
};

inline QString State2StdString(State state)
{
    switch (state) {
        case State::Paused: return "Paused";
        case State::Running: return "Running";
        default: return "-";
    }
}

enum class Side
{
    Buy,
    Sell
};

inline QString Side2StdString(Side side)
{
    switch (side) {
        case Side::Buy: return "Buy";
        case Side::Sell: return "Sell";
        default: return "-";
    }
}

struct StrategyUpdate
{
    int             strategyId;
    Type            type;
    std::string     name;
    State           state;
};
Q_DECLARE_METATYPE(StrategyUpdate)

struct OrderUpdate
{
    int             orderId;
    int             strategyId;
    double          price;
    double          active_volume;
    double          filled_volume;
    Side            side;
};
Q_DECLARE_METATYPE(OrderUpdate)

#endif // MESAJLAR_H
