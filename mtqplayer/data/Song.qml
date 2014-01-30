import QtQuick 2.0
import mtq.widgets 1.0

Item {

    GenericButton {

        id: waveLane
        height: waveHeight
        width: 200
        anchors.fill: parent
        color: "#ffffff"

        onMtqTap: {
            //waveLane.y += waveLane.height

            //lane.visible = false
            waveLane.visible = false

            //songPicker.x = tap.x - songPicker.width/2
            //songPicker.y = tap.y - songPicker.height/2
            songPicker.visible = true
        }


        Image {
            source: imagePath
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
