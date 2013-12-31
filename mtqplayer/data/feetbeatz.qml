import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"

    Rectangle {
        id: lane1
        width: 200
        height: 2400
        x: 500
        y: 0
        color: "#ffffff"

        MouseArea {
            anchors.fill: parent
            onClicked: parent.color = "blue"
        }
    }

    Rectangle {
        id: lane2
        width: 200
        height: 2400
        x: 2000
        y: 0
        color: "#ffffff"
    }

    Slider {
        id: crossfader
        x: lane1.x + 400
        y: 1400
        width: 800
        height: 50
    }

    /*
    Label {
        id: helloLabel
		x: 200
		y: 400
        width: 650
        height: 160
        text: "asdf asdf"
		rotation: -20
    }

    PushButton {
		id: addNameButton
		x: 850
		y: 550
		width: 400
		height: 150
		text: "Add my Name!"
        onPressed: {
            helloLabel.text += " from Adrian"
		}
    }
    */
}
