import QtQuick 2.0
import QtMultimedia 5.0
import mtq.widgets 1.0
//import fb.player 1.0 //wtf


Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"

    FjSlider {
        id: crossfader
        x: 2500
        y: 1500
        width: 700
        height: 300
        onMtqTapDown: {
            player.setVolume(1, 1-crossfader.value);
            player.setVolume(2, crossfader.value);
        }
    }

    FjPlayer {
        //utility overflow
        id: player
        width: 100
        height: 100
        visible: false
        x: -300
        y: -300
    }

    PaintField {
        x: 0
        y: 1500
        height: 5
        width: 4096
    }

    GenericButton
    {
        id: lane1
        x: 2000
        y: 0
        visible: true
        height: 2400
        width: 200
        color: "#ccffff"
        onMtqTapDown: {
            lane1.visible = false;
            songPicker.visible=true
        }

    }

    ListPicker {
        id: songPicker
        x: 1800
        y: 1500
        width: 800
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
                player.changeTrack(1, 2);
                laneImageChubby.visible = true
                songPicker.visible = false
            }
            else if (selectedItem == 1) {
                player.changeTrack(1,1);
                laneImageParov.visible = true
                songPicker.visible = false
            }
            else if (selectedItem == 2) {
                player.changeTrack(1,0);
                laneImageBeach.visible = true
                songPicker.visible = false
            }

        }
    }


    PushButton {
        id: laneImageChubby
        x: 2000
        y: 1500-laneImageChubby.height
        height: 1762.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/chubbyChecker.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 141000 }
        }

        onMtqTapDown: {
            laneImageChubby.y +=laneImageChubby.height
            player.play(1);
        }

    }


    PushButton {
        id: laneImageParov
        x: 2000
        y: 1500-laneImageParov.height
        height: 2962.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/catgroove.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 237000 }
        }

        onMtqTapDown: {
            laneImageParov.y +=laneImageParov.height
            player.play(1);
        }

    }

    PushButton {
        id: laneImageBeach
        x: 2000
        y: 1500-laneImageBeach.height
        height: 1887.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/surfin.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 151000 }
        }

        onMtqTapDown: {
            laneImageBeach.y +=laneImageBeach.height
            player.play(1);
        }

    }



    GenericButton
    {
        id: lane2
        x: 3500
        y: 0
        visible: true
        height: 2400
        width: 200
        color: "#ccffff"
        onMtqTapDown: {
            lane2.visible = false;
            songPicker2.visible=true
        }

    }

    ListPicker {
        id: songPicker2
        x: 3200
        y: 1500
        width: 800
        height: 400
        visible: false
        selectedItem: 0
        caption: "Songs"

        Component.onCompleted: {
            songPicker2.addItem("Chubby Checker - Let's Twist again");
            songPicker2.addItem("Parov Stella
r - Catgroove");
            songPicker2.addItem("Beach Boys - Surfin' USA")
        }

        onSelectedItemChanged: {
            if (selectedItem == 0) {
                player.changeTrack(2,2);
                laneImageChubby2.visible = true
                songPicker2.visible = false
            }
            else if (selectedItem == 1) {
                player.changeTrack(2,1);
                laneImageParov2.visible = true
                songPicker2.visible = false
            }
            else if (selectedItem == 2) {
                player.changeTrack(2,0);
                laneImageBeach2.visible = true
                songPicker2.visible = false
            }

        }
    }


    PushButton {
        id: laneImageChubby2
        x: 3200
        y: 1500-laneImageChubby2.height
        height: 1762.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/chubbyChecker.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 141000 }
        }

        onMtqTapDown: {
            laneImageChubby2.y +=laneImageChubby2.height
            player.play(2);
        }

    }


    PushButton {
        id: laneImageParov2
        x: 3200
        y: 1500-laneImageParov2.height
        height: 2962.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/catgroove.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 237000 }
        }

        onMtqTapDown: {
            laneImageParov2.y +=laneImageParov2.height
            player.play(2);
        }

    }

    PushButton {
        id: laneImageBeach2
        x: 3200
        y: 1500-laneImageBeach2.height
        height: 1887.5
        width: 200
        visible: false

        Image {
        source: "/home/hci1/dis13_group8/mtqplayer/images/surfin.png"
            anchors.fill: parent
        }
        Behavior on y {
            NumberAnimation { duration: 151000 }
        }

        onMtqTapDown: {
            laneImageBeach2.y +=laneImageBeach2.height
            player.play(2);
        }

    }

    PushButton {
        id: flanger
        x: 100
        y: 100
        height: 200
        width: 300
        visible: true
        text: flanger
        onMtqTapDown: {
            player.toggleEffect(1,1);
        }
    }

    PushButton {
        id: reverb
        x: 400
        y: 500
        height: 200
        width: 300
        visible: true
        text: reverb
        onMtqTapDown: {
            player.toggleEffect(1,2);
        }
    }

    GenericButton {
       id: controlPad
       x: 100
       y: 1000
       height: 300
       width: 300
       visible: true
       onMtqTapDown: {
           controlPad.x += event.mappedCenter.x -150;
           controlPad.y += event.mappedCenter.y -150;

       }
    }

    ToggleButton {
        id: toggleA
        visible: true
        x: 100
        y: 1500
        height: 100
        width: 300
        activeTitle: "ON"
        inactiveTitle: "OFF"
    }
    Text {
        text: "Track A"
        x: 450
        y: 1510
        height: 100
        width: 300
        font.pointSize: 48
        color: "white"
    }

    ToggleButton {
        id: toggleB
        visible: true
        x: 100
        y: 1650
        height: 100
        width: 300
        activeTitle: "ON"
        inactiveTitle: "OFF"
    }
    Text {
        text: "Track B"
        x: 450
        y: 1660
        height: 100
        width: 300
        font.pointSize: 48
        color: "white"
    }

}
