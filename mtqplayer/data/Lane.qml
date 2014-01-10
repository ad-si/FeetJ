import QtQuick 2.0
import mtq.widgets 1.0


Item {
    id: laneContainer

    property alias laneColor: lane.color

    //signal clicked(string songName)


    Rectangle {
        id: lane
        width: 200
        height: 2400
        x: 0
        y: 0
        color: "#ffaaaa"

        MouseArea {
            id: playArea
            anchors.fill: parent
            onPressed:  {
                lane.visible = false
                songPicker.x = mouse.x - songPicker.width/2
                songPicker.y = mouse.y - songPicker.height/2
                songPicker.visible = true
            }
        }

        Text {
            text: "+"
            anchors.centerIn: parent
            font {
                family: "Helvetica"
                pointSize: 100
            }
        }
    }

    Songpicker {
        id: songPicker
    }
}
