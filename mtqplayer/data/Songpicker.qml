import QtQuick 2.0
import mtq.widgets 1.0
import "feetj.js" as FeetJ


Item {

    property alias pickerWidth: songPicker.width
    property alias pickerHeight: songPicker.height

    ListPicker {
        id: songPicker
        width: 700
        height: FeetJ.songs.length * 80
        selectedItem: 0
        caption: 'Songs'

        Component.onCompleted: {

            FeetJ.songs.forEach(function(song){
                songPicker.addItem(song.name)
            })
        }

        onSelectedItemChanged: {

            songPicker.visible = false

            parent.parent.state = 'stop'

            FeetJ.loadSong(FeetJ.songs[selectedItem], parent.parent)
        }
    }
}
