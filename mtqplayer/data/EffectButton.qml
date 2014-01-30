import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: effectButton
    height: 200
    width: 300

    Label {
        id: effectButtonLabel
        text: "Effekt"
    }

    MouseArea {
        anchors.fill: parent
        onPressed: effectButtonLabel.text = "jo!"
    }
}
