import QtQuick 2.0
import mtq.widgets 1.0

Item {

    property string imagePath
    property double waveHeight
    property int songDuration

    GenericButton {

        id: waveLane
        height: 2400 //waveheight
        width: 200
        anchors.fill: parent
        color: "#222222"

        onMtqTap: {
            //waveLane.y += waveLane.height

            //lane.visible = false
            waveLane.visible = false

            //songPicker.x = tap.x - songPicker.width/2
            //songPicker.y = tap.y - songPicker.height/2
            //songPicker.visible = true
        }


        Image {
            source: "/home/hci1/dis13_group8/mtqplayer/songs/catgroove.png"
            anchors.fill: parent
        }

        /*
        Behavior on y {
            NumberAnimation {
                duration: songDuration
            }

        }
        */

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
