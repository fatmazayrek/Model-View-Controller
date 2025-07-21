import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Repeater")

    ListModel {
        id: listModel

        ListElement { name: "Abigail"; age: 22 }
        ListElement { name: "Andrew"; age: 45 }
        ListElement { name: "Mikail"; age: 33 }
        ListElement { name: "Melissa"; age: 21 }
        ListElement { name: "Anabel"; age: 23 }
    }

    Flickable {
        anchors.fill: parent
        contentHeight: 500              // icerik boyutunu vermediginde calismadi

        Column {
            anchors.fill: parent

            Repeater {
                model: listModel
                delegate: delegateId
            }
        }
    }

    Component {
        id: delegateId

        Rectangle {
            height: 50
            width: parent.width

            color: "yellowgreen"
            border.color: "green"

            Column {
                anchors.fill: parent
                spacing: 3

                Text {
                    text: name
                    font.pointSize: 15
                }

                Text {
                    text: age
                    font.pointSize: 9
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Name - Age: ", name, " - ", age)
                }
            }
        }
    }
}
