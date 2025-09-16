import QtQuick

Item {
    id: orderMenuID

    ListView {
        id: listViewId
        anchors.fill: parent
        clip: true

        model: MainController.orderModel
        spacing: 4

        orientation: ListView.Vertical

        delegate: Rectangle {
            id: delegateId
            width: 220
            height: 100
            color: "beige"
            border.color: "black"
            border.width: 1

            Column {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 2

                Text {
                    text: "ORDER ID: " + orderId
                }

                Text {
                    text: "STRATEGY ID: " + strategyId
                }

                Text {
                    text: "PRICE: " + price
                }

                Text {
                    text: "SIDE: " + side
                }
            }
        }
    }
}
