import QtQuick
import QtQml.Base

Window {
    id: root
    width: 500
    height: 500
    visible: true
    title: qsTr("Header, Footer and Highlight")

    property var list: ["JANUARY",
                        "FEBRUARY",
                        "MARCH",
                        "APRIL",
                        "MAY",
                        "JUNE",
                        "JULY",
                        "AUGUST",
                        "SEPTEMBER",
                        "OCTOBER",
                        "NOVEMBER",
                        "DECEMBER"]

    ListView {
        id: listViewID
        anchors.fill: parent
        model: list
        delegate: Rectangle {
            id: delegateID
            width: parent.width
            height: 50
            color: "beige"
            border.color: "red"
            radius: 5

            Text {
                id: tetID
                text: modelData
                font.pointSize: 15
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(modelData)
                    listViewID.currentIndex = index
                }
            }
        }
        header: headerID
        footer: footerID
        highlight: Rectangle {
            width: 180;
            height: 40
            color: "lightsteelblue";
            radius: 5
            opacity: 0.5
            z: 2
        }
    }

    Component {
        id: headerID

        Rectangle {
            id: headerRect
            width: root.width
            height: 50
            color: "yellowgreen"

            Text {
                id: headerTextID
                text: qsTr("Months")
                anchors.centerIn: parent
                font.pointSize: 20
            }
        }
    }

    Component {
        id: footerID

        Rectangle {
            id: footerRect
            width: root.width
            height: 50
            color: "blue"
        }
    }
}
