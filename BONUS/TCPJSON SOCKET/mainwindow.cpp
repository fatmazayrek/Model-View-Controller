#include "mainwindow.h"
#include "ui_mainwindow.h"

// QT Libs
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) ,
    mStrategyServer{ new QTcpServer(this)},
    mOrderServer{ new QTcpServer(this)}
{
    ui->setupUi(this);

    connect(mStrategyServer, &QTcpServer::newConnection, this, &MainWindow::onNewStrategyConnection);
    connect(mOrderServer, &QTcpServer::newConnection, this, &MainWindow::onNewOrderConnection);

    // Soket dinlemeye baslar
    // DEFAULT parametrelerle dinlemeye gecer
    mStrategyServer->listen(QHostAddress::LocalHost, 5200);
    mOrderServer->listen(QHostAddress::LocalHost, 5201);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewStrategyConnection()
{
    QTcpSocket *clientSocket = mStrategyServer->nextPendingConnection();
    clientSocket->setParent(this);              // memory leak engelle
    mStrategyClients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::onStrategyDisconnect);

    ui->stragetyLabel->setText("Yeni istemci bağlandı: " + clientSocket->peerAddress().toString());
}

void MainWindow::onStrategyDisconnect()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    mStrategyClients.removeAll(clientSocket);
    clientSocket->deleteLater();

    ui->stragetyLabel->setText("İstemci bağlantısı koptu");
}

void MainWindow::onNewOrderConnection()
{
    QTcpSocket *clientSocket = mOrderServer->nextPendingConnection();
    clientSocket->setParent(this);              // memory leak engelle
    mOrderClients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::disconnected, this, &MainWindow::onOrderDisconnect);

    ui->orderLabel->setText("Yeni istemci bağlandı: " + clientSocket->peerAddress().toString());
}

void MainWindow::onOrderDisconnect()
{
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    mOrderClients.removeAll(clientSocket);
    clientSocket->deleteLater();

    ui->orderLabel->setText("İstemci bağlantısı koptu");
}

void MainWindow::on_strategyGonder_clicked()
{
    QString jsonText = ui->strategy->toPlainText();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonText.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        ui->stragetyLabel->setText("Geçersiz JSON, Lütfen geçerli JSON formatında metin giriniz.");
        return;
    }

    QByteArray data = doc.toJson(QJsonDocument::Compact);
    for (auto client : mStrategyClients) {
        if(client->state() == QAbstractSocket::ConnectedState) {
            client->write(data);
            client->flush();
        }
    }
}

void MainWindow::on_orderGonder_clicked()
{
    QString jsonText = ui->order->toPlainText();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonText.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        ui->orderLabel->setText("Geçersiz JSON, Lütfen geçerli JSON formatında metin giriniz.");
        return;
    }

    QByteArray data = doc.toJson(QJsonDocument::Compact);
    for (auto client : mOrderClients) {
        if(client->state() == QAbstractSocket::ConnectedState) {
            client->write(data);
            client->flush();
        }
    }
}

