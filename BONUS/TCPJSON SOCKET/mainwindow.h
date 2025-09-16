#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QT Libs
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!
     * \brief onNewStrategyConnection
     * Strategy soketine baglanti saglandiginda calisir
     */
    void onNewStrategyConnection();

    /*!
     * \brief onStrategyDisconnect
     * Strategy soketi baglanti koparirsa calisir
     */
    void onStrategyDisconnect();

    /*!
     * \brief onNewOrderConnection
     * Order soketine baglanti saglandiginda calisir
     */
    void onNewOrderConnection();

    /*!
     * \brief onOrderDisconnect
     * Order soketi baglanti koparirsa calisir
     */
    void onOrderDisconnect();

    // BUTONs
    void on_strategyGonder_clicked();
    void on_orderGonder_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *mStrategyServer;
    QTcpServer *mOrderServer;
    QList<QTcpSocket*> mStrategyClients;
    QList<QTcpSocket*> mOrderClients;
};
#endif // MAINWINDOW_H
