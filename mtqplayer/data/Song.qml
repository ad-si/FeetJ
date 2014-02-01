import QtQuick 2.0
import mtq.widgets 1.0
import "feetj.js" as FeetJ

Item {

    id: songContainer
    height: 2400
    width: 200

    property double waveHeight
    property int songDuration
    property string imageName: 'placeholder'

    GenericButton {

        id: song
        anchors.fill: parent
        color: '#323232'

        onMtqTap: {

            FeetJ.configurate({
                x: event.mappedCenter.x,
                y: event.mappedCenter.y
            })
            FeetJ.addSongPickerTo(songContainer)
        }

        Image {
            source: "/home/hci1/dis13_group8/mtqplayer/songs/" + imageName + ".png"
            anchors.fill: parent
        }

        Text {
            text: "+"
            color: 'white'
            anchors.centerIn: parent
            font {
                family: "Helvetica"
                pointSize: 100
            }
        }
    }
}
