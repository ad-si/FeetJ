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
        clip: true
        color: "transparent"

        Song {
            anchors.fill: parent
        }

    }

    Songpicker {
        id: songPicker
        visible: false
    }
}
