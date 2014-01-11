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
        color: "#ffaaaa"


        GenericButton {
            id: waveLane
            height: waveHeight
            width: 200
            x: 0
            y: 1500 - waveHeight
            color: "#ffffff"

            onMtqTap: {
                waveLane.y += waveLane.height
            }


            Image {
                source: imagePath
                anchors.fill: parent
            }

            Behavior on y {
                NumberAnimation {
                    duration: songDuration
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
    }

    Songpicker {
        id: songPicker
    }
}
