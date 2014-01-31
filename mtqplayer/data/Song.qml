import QtQuick 2.0
import mtq.widgets 1.0
import "feetj.js" as FeetJ

Item {

    id: songContainer
    height: 2400
    width: 200

    property string imagePath
    property double waveHeight
    property int songDuration

    GenericButton {

        id: song
        anchors.fill: parent
        color: "#222222"

        onMtqTap: {
            //waveLane.y += waveLane.height

            //lane.visible = false
            song.visible = false

            //songPicker.x = tap.x - songPicker.width/2
            //songPicker.y = tap.y - songPicker.height/2
            //songPicker.visible = true

            FeetJ.configurate({
                x: event.mappedCenter.x,
                y: event.mappedCenter.y
            })
            FeetJ.addSongPickerTo(songContainer)
        }

        Image {
            source: "/home/hci1/dis13_group8/mtqplayer/songs/catgroove.png"
            anchors.fill: parent
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
