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
        }

        GenericButton {
            id: laneBSelectors
        }
    }

    Column {

        anchors.top: laneSelectorButtons.bottom
        anchors.topMargin: 40
        anchors.right: parent.right

        spacing: 10

        GenericButton {
            id: effect1
        }

        GenericButton {
            id: effect2
        }

        GenericButton {
            id: effect3
        }
    }
}
