import QtQuick 2.0

Rectangle {
    id: effectButton
    height: 200
    width: 300
    x: 500
    y: 300

    Label {
        id: effectButtonLabel
        text: "Effekt"
    }

    MouseArea {
        anchors.fill: parent
        onPressed: effectButtonLabel.text = "jo!"
    }
}
