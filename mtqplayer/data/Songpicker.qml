import QtQuick 2.0
import mtq.widgets 1.0


Item {

    ListPicker {
        id: songPicker
        width: 700
        height: 400
        selectedItem: 0
        caption: "Songs"

        Component.onCompleted: {
            songPicker.addItem("Chubby Checker - Let's Twist again")
            songPicker.addItem("Parov Stellar - Catgroove")
            songPicker.addItem("Beach Boys - Surfin' USA")
        }

        onSelectedItemChanged: {
            if (selectedItem == 0) {
                songPicker.visible = false
     //           lane1.visible = true
            }
            else if (selectedItem == 1) {
                songPicker.visible = false
         //       lane1.visible = true
            }
            else if (selectedItem == 2) {
                songPicker.visible = false
           //     lane2.visible = true

            }
        }
    }

    Rectangle {

    }

   // Lane {
        //id: lane1
        //imagePath: "/home/hci1/dis13_group8/mtqplayer/images/chubbychecker.png"
        //songDuration: 141000
     //   waveHeight: 1763
   // }
}
