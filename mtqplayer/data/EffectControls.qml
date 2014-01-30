import QtQuick 2.0
import mtq.widgets 1.0

Item {

    Column {

        id: laneSelectorButtons
        anchors.right: parent.right
        y: 500

        spacing: 10


        GenericButton {
            id: laneASelectors
            text: "Lane A"
            color: "#323232"
        }

        GenericButton {
            id: laneBSelectors
            text: "Lane B"
            color: "#323232"
        }
    }

    Column {

        anchors.top: laneSelectorButtons.bottom
        anchors.topMargin: 40
        anchors.right: parent.right

        spacing: 10

        GenericButton {
            id: effect1
            text: "Delay"
            color: "#323232"
        }

        GenericButton {
            id: effect2
            text: "Reverb"
            color: "#323232"
        }

        GenericButton {
            id: effect3
            text: "Flanger"
            color: "#323232"
        }
    }
}
