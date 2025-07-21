import QtQuick

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Decoration and Section")

    ListModel {
        id: listModelID
        ListElement {
            name: "Fatma Z."
            company: "GOOGLE"
            age: 27
        }

        ListElement {                               // NOTE : Ayni group id'ler alt alta yer almalidir. Aksi durumda gruplanma olmuyor
            name: "Özge İ."
            company: "GOOGLE"
            age: 32
        }

        ListElement {
            name: "Zehra Z."
            company: "ZEKI"
            age: 26
        }

        ListElement {
            name: "İbrahim Z."
            company: "MERCEDES"
            age: 18
        }

        ListElement {
            name: "Turan K."
            company: "HUKUK"
            age: 18
        }
    }

    ListView {
        id: listViewID
        anchors.fill: parent
        model: listModelID
        delegate: delegateID
        section {
            property: "company"
            criteria: ViewSection.FullString
            delegate: Rectangle {
                width: root.width
                height: 40
                color: "red"

                Text {
                    text: section
                    anchors.centerIn: parent
                    font.pointSize: 15
                }
            }
        }
    }

    Component {
        id: delegateID

        Rectangle {
            width: root.width
            height: 50
            color: "beige"
            border.color: "yellowgreen"
            radius: 15

            Text {
                text: name
                anchors.centerIn: parent
                font.pointSize: 20
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("NAME: ", name)
                }
            }
        }
    }
}
