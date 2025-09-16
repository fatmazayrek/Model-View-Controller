import QtQuick

Item {
    id: topMenuID

    ListView {
        id: listViewId
        anchors.fill: parent

        model: MainController.strategyModel
        spacing: 4

        orientation: ListView.Vertical

        delegate: Rectangle {
            id: delegateId
            width: 110
            height: 50
            radius: 20
            color: (status === "Running") ? "limegreen" : "silver"
            border.color: "black"
            border.width: 1

            Column {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 2

                Text {
                    text: "STRATEGY: " + strategyId
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    var id = strategyId
                    if (MainController.clickedStrategyId === strategyId) {
                        id = -1
                    }

                    MainController.strategyClicked(id)
                }

                onEntered: (status === "Running") ? delegateId.color = "darkolivegreen" : delegateId.color = "slategray"
                onExited: (status === "Running") ? delegateId.color = "limegreen" : delegateId.color = "silver"
            }
        }
    }
}
