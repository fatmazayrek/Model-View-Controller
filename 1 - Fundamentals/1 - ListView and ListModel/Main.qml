import QtQuick
import QtQuick.Layouts

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("ListView and ListModel")

    ListView {
        anchors.fill: parent
        model: modelId
        header: headerId
        delegate: delegateId
    }

    ListModel {
        id: modelId

        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 3.25
        }
        ListElement {
            name: "Banana"
            cost: 1.95
        }
        ListElement {
            name: "Kiwi"
            cost: 9.95
        }
        ListElement {
            name: "Watermelon"
            cost: 12.45
        }
    }

    Component {
        id: headerId
        RowLayout {
            id: layoutId
            spacing: 10
            width: parent.width
            height: 50

            Rectangle {
                width: ((parent.width / 2) - 10); height: parent.height
                color: "coral"
                Layout.leftMargin: 10
                radius: 10
                clip: true

                Text {
                    text: qsTr("Fruit Name")
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }

            Rectangle {
                width: ((parent.width / 2) - 10); height: parent.height
                color: "coral"
                Layout.leftMargin: 10
                radius: 10
                clip: true

                Text {
                    text: qsTr("Cost Name")
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }
        }
    }

    Component {
        id: delegateId
        Row {
            spacing: 10
            width: parent.width
            height: 50

            Rectangle {
                width: ((parent.width / 2) - 10); height: parent.height
                color: "lemonchiffon"
                border.color: "goldenrod"
                radius: 10
                clip: true

                Text {
                    text: name
                    anchors.centerIn: parent
                    font.pointSize: 20
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Index: ", index)
                    }
                }
            }

            Rectangle {
                width: ((parent.width / 2) - 10); height: parent.height
                color: "lemonchiffon"
                border.color: "goldenrod"
                radius: 10
                clip: true

                Text {
                    text: cost + " $"
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }

        }
    }
}
