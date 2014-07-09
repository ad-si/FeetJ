import QtQuick 2.0
import mtq.widgets 1.0


Item {

    //property alias laneColor: lane.color

    //signal clicked(string songName)

    Rectangle {
        width: 200
        height: 2400
        color: "transparent"

        Song {
            anchors.fill: parent
        }
    }
}
