import QtQuick 2.0
import mtq.widgets 1.0


Item {
    id: laneContainer

    property alias laneColor: lane.color
    property string imagePath
    property double waveHeight
    property int songDuration

    //signal clicked(string songName)

    Rectangle {
        id: lane
        width: 200
        height: 2400
        clip: true
        color: "transparent"

        Song {

        }

    }

    Songpicker {
        id: songPicker
        visible: false
    }
}
