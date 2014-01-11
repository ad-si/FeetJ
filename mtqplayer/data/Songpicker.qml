import QtQuick 2.0
import mtq.widgets 1.0


ListPicker {
    id: songPicker
    width: 400
    height: 400
    visible: false
    selectedItem: 0
    caption: "Songs"

    Component.onCompleted: {
        songPicker.addItem("Chubby Checker - Let's Twist again");
        songPicker.addItem("Parov Stellar - Catgroove");
        songPicker.addItem("Beach Boys - Surfin' USA")
    }

    onSelectedItemChanged: {
        if (selectedItem == 0) {
            songPicker.visible = false


        }
        else if (selectedItem == 1) {
            laneImageParov.visible = true
            songPicker.visible = false
        }
        else if (selectedItem == 2) {
            laneImageBeach.visible = true
            songPicker.visible = false
        }
    }

    Lane {
        imagePath: "/home/hci1/dis13_group8/mtqplayer/images/chubbychecker.png"
        songDuration: 141000
        waveHeight: 1762.5
    }


    function startSong(name){
        var map = {
            0: "acdc",
            1: "nirvana",
            2: "biggerthanhiphop",
            3: "catgroove",
            4: "jeffer",
            5: "surfin_usa",
            6: "biggerthanhiphop",
            7: "highwaytohel",
            8: "letstwistagain",
            9: "talkdirty",
            10: "bonkers",
            11: "i_would",
            12: "nirvana",
            13: "touchmyhorn"
        }
    }
}
