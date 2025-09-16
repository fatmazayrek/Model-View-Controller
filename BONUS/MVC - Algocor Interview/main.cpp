#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// INNER Class
#include "haberlesme/tcpmanager.h"
#include "haberlesme/tcpsoketlib.h"
#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // SOKET
    TcpSoketLib strategySoket("127.0.0.1", 5200);
    TcpSoketLib orderSoket("127.0.0.1", 5201);
    TcpManager manager;

    // MAIN
    MainController mainController;

    // CONNECT SIGNAL & SLOTS
    QObject::connect(&strategySoket, &TcpSoketLib::VeriAlindi, &manager, &TcpManager::onStrategyVerisiAlindi);
    QObject::connect(&orderSoket, &TcpSoketLib::VeriAlindi, &manager, &TcpManager::onOrderVerisiAlindi);

    QObject::connect(&manager, &TcpManager::UpdateStrategy, &mainController, &MainController::onUpdateStrategy);
    QObject::connect(&manager, &TcpManager::UpdateOrders, &mainController, &MainController::onUpdateOrder);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MainController", &mainController);

    const QUrl url(QStringLiteral("qrc:/HOMEWORK/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    strategySoket.onConnect();
    orderSoket.onConnect();

    return app.exec();
}
