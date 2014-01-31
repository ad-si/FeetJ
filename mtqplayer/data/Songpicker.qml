import QtQuick 2.0
import mtq.widgets 1.0
import "feetj.js" as FeetJ
import "songs.js" as Songs


Item {

    property alias pickerWidth: songPicker.width
    property alias pickerHeight: songPicker.height

    ListPicker {
        id: songPicker
        width: 700
        height: Songs.all.length * 80
        selectedItem: 0
        caption: "Songs"

        Component.onCompleted: {

            Songs.all.forEach(function(song){
                songPicker.addItem(song.name)
            })
        }

        onSelectedItemChanged: {

            songPicker.visible = false

            FeetJ.loadSong(Songs.all[selectedItem])
        }
    }

   // Lane {
        //id: lane1
        //imagePath: "/home/hci1/dis13_group8/mtqplayer/images/chubbychecker.png"
        //songDuration: 141000
     //   waveHeight: 1763
   // }
}
