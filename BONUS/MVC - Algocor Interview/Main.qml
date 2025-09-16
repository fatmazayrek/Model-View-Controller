import QtQuick
import QtQuick.Layouts

Window {
    id: rootID

    width: 640
    height: 480
    visible: true
    title: qsTr("QT System Design - Fatma ZAYREK")

    LeftMenu {
        id: leftMenuID

        anchors {
            top: parent.top
            topMargin: 15
            left: parent.left
            leftMargin: 15
        }

        width: 200
        height: rootID.height
    }

    Rectangle {
        id: lineID

        width: 2
        height: parent.height
        color: "darkgray"

        anchors {
            left: leftMenuID.right
            leftMargin: 10
            top: parent.top
        }
    }

    Rectangle {
        id: strategyInfoBox

        width: 300
        height: 40
        color: "transparent"
        clip: true

        border {
            color: "black"
            width: 1
        }

        anchors.left: lineID.right
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

        Column {
            anchors.fill: parent
            anchors.leftMargin: 5
            spacing: 4

            Text {
                text: qsTr("Strategy Bilgileri: ")
            }

            Row {
                spacing: 10

                Text {
                    text: qsTr("TYPE: ") + MainController.strategyType
                }

                Text {
                    text: qsTr("NAME: ") + MainController.strategyName
                }

                Text {
                    text: qsTr("STATE: ") + MainController.strategyState
                }
            }
        }
    }

    OrderMenu {
        id: orderMenuID

        anchors {
            top: strategyInfoBox.bottom
            topMargin: 15
            left: lineID.right
            leftMargin: 15
        }

        width: 300
        height: rootID.height

    }


}
