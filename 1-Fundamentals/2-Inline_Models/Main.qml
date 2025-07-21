import QtQuick
import QtQuick.Controls

Window {
    id: root
    width: 100
    height: 200
    visible: true
    title: qsTr("Inline Models")

    property var list : ["KANAL 1", "KANAL 2", "KANAL 3", "KANAL 4", "KANAL 5", "KANAL 6", "KANAL 7", "KANAL 8", "KANAL 9", "KANAL 10"]
    property int kanalNo : 10
    property var list2 : list.slice(0, 6)

    /* ListView {
        id: listView
        anchors.fill: parent
        model: list2
        delegate: Rectangle {
            id: delegateId
            width: root.width
            height: 30
            color: mouseAreaId.containsMouse ?  "beige" : "darkkhaki"
            border {
                color: "black"
                width: 1
            }
            radius: 10

            Text {
                id: textId
                anchors.centerIn: parent
                font.pointSize: 12
                text: modelData
            }

            MouseArea {
                id: mouseAreaId
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    console.log(index)
                }
            }
        }
    } */

    ComboBox {
        id: mainCombobox
        height: 50; width: 100
        anchors.centerIn: parent
        model: list2

        onHighlighted: (index) => {
            console.log(valueAt(index))
        }
    }
}
