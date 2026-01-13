import QtQuick
import QtQuick.Layouts
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dynamic Models")

    property int counter: 0

    ListModel {
        id: listModelId

        ListElement {
            firstName: "Nazire"
            lastName: "Baklavacıoğlu"
        }

        ListElement {
            firstName: "Leyla"
            lastName: "Tekin"
        }

        ListElement {
            firstName: "Ali Rıza"
            lastName: "Tekin"
        }
    }

    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: listViewId
            model: listModelId
            delegate: delegateId

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: addButtonId
            text: "Ekle"
            Layout.fillWidth: true

            background: Rectangle {
                color: "lightgreen"
                radius: 15
            }

            onClicked: function() {
                listModelId.append({
                                       "firstName": "Fatma",
                                       "lastName": "Zayrek - " + counter
                                   })
                counter++
            }
        }

        Button {
            id: removeButtonId
            text: "Çıkar"
            Layout.fillWidth: true

            background: Rectangle {
                color: "lightcoral"
                radius: 15
            }

            onClicked: function() {
                if (listModelId.count >= 1) {
                    listModelId.remove(listModelId.count - 1)
                }
            }
        }

        Button {
            id: clearButtonId
            text: "Temizle"
            Layout.fillWidth: true

            background: Rectangle {
                color: "lightsalmon"
                radius: 15
            }

            onClicked: function() {
                listModelId.clear()

                counter = 0
            }
        }

        Button {
            id: removeIndekButtonId
            text: "Sıradakini Çıkar"
            Layout.fillWidth: true

            background: Rectangle {
                color: "orange"
                radius: 15
            }

            onClicked: function() {
                if (listModelId.count >=2) {
                    listModelId.remove(1)
                }
            }
        }

        Button {
            id: setButtonId
            text: "Editle"
            Layout.fillWidth: true

            background: Rectangle {
                color: "yellowgreen"
                radius: 15
            }

            onClicked: function() {
                if (listModelId.count >= 2) {
                    var jsonObject = {
                            "firstName" : "Selami" ,
                            "lastName" : "Yurtsever"
                    }

                    listModelId.set(1, jsonObject)
                }
            }
        }
    }

    Component {
        id: delegateId

        Rectangle {
            width: parent.width
            height: 50
            color: "beige"
            border.color: "yellowgreen"
            radius: 15

            Text {
                anchors.centerIn: parent
                text: firstName + " " + lastName
                font.pointSize: 20
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Indeks: ", index)
                }
            }
        }
    }

}
