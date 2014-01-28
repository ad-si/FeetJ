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
            songPicker2.addItem("Parov Stellar - Catgroove");
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

    /*FjPlayer {
        id: player
        x:-300
        y:-300
        height: 100
        width: 100
        visible: false

    }

    FjSlider {
        id: crossfader
        x: 100
        y: 100
        width: 500
        height: 200
        visible: true
        onMtqTapDown: {
            //player.test();
        }

    }*/



  /*  Slider {
        id: slidor
        y: 500
        x: 500
        width: 500
        height: 200
        visible: true

        onMtqTapDown: {
            player.changeTrack(1, 0);
            helloLabel.text = slidor.value;
            player.crossfade(slidor.value);

        }
    }

    Label {
        id: helloLabel
        x: 500
        y: 800
        width: 3000
        text: "WURST macht gesund!"
    }*/

}



/*Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"


    Rectangle {
        id: lane1
        width: 200
        height: 2400
        x: 500
        y: 0
        color: "#ffffff"
    }

    Rectangle {
        id: silence
        width: 200
        height: 200
        x: 250
        y: 250
        color: "#ff9999"

        signal qmlSignal()

        MouseArea {
            id: stopArea
            anchors.fill: parent
            onPressed:  {
                acdc.stop()
                nirvana.stop()
                //songLabel.text = "stopped."
                silence.qmlSignal();

                }
            }
        }

        Rectangle {
            id: statusButton
            width: 200
            height: 200
            x: 0
            y: 250
            color: "#99ff99"
            MouseArea {
                id: statusArea
                anchors.fill: parent
                onPressed:  {

                    songLabel.text = acdc.status
                }
             }
    }

        ToggleButton {
            id: playPause
            x: 50
            y: 350
            width: 400
            height: 160
            activeTitle: "PLAY"
            inactiveTitle: "STOP"
        }

        ToggleButton {
            id: musicChooser
            x: 0
            y: 650
            width: 400
            height: 160
            activeTitle: "ADCD"
            inactiveTitle: "Nirvana"
        }

    Rectangle {
        id: lane2container
        x: 2000
        y: 0

        Rectangle {
            id: lane2
            width: 200
            height: 2400
            x: 0
            y: 0
            color: "#ffffff"

            MouseArea {
                id: playArea
                anchors.fill: parent
                onPressed:  {
                    lane2.visible = false
                    songPicker.x = mouse.x
                    songPicker.y = mouse.y
                    songPicker.visible = true
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

        ListPicker {
            id: songPicker
            width: 400
            height: 400
            visible: true
            selectedItem: 0
            caption: "Songs"

            Component.onCompleted: {
                songPicker.addItem("ACDC");
                songPicker.addItem("Nirvana");
            }

            onSelectedItemChanged: {
                if (selectedItem == 0) {
                    nirvana.stop()
                    acdc.play()
                    songLabel.text = "ACDC!"
                    lane2.visible = true
                    songPicker.visible = false
                }
                else if (selectedItem == 1) {
                    acdc.stop()
                    nirvana.play()
                    songLabel.text = "Nirvana!"
                }
            }

            function startSong(name){

            }
        }
    }

    Rectangle {
        id: effectsContainer
        x: 2600
        y: 100
        height: 1300
        width: 1300
        color: "#ffaaaa"

        Rectangle {
            id: effectButton1
            height: 200
            width: 300
            x: 100
            y: 300
            color: "#aaffaa"

            Label {
                id: effectButton1Label
                text: "Effekt 1"
            }

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onPressed: effectButton1Label.text = "jo!"
            }

        }

        Rectangle {
            id: effectButton2
            height: 200
            width: 300
            x: 500
            y: 300

            Label {
                id: effectButton2Label
                text: "Effekt 1"
            }

            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onPressed: effectButton2Label.text = "jo!"
            }
        }

        Rectangle {
            id: effectButton3
            height: 200
            width: 300
            x: 900
            y: 300

            Label {
                id: effectButton3Label
                text: "Effekt 1"
            }

            MouseArea {
                id: mouseArea3
                anchors.fill: parent
                onPressed: effectButton3Label.text = "jo!"
            }
        }

        Rectangle {
            id: effectButton4
            height: 200
            width: 300
            x: 100
            y: 800

            Label {
                id: effectButton4Label
                text: "Effekt 4"
            }

            MouseArea {
                id: mouseArea4
                anchors.fill: parent
                onPressed: effectButton4Label.text = "jo!"
            }
        }

        Rectangle {
            id: effectButton5
            height: 200
            width: 300
            x: 500
            y: 800

            Label {
                id: effectButton5Label
                text: "Effekt 5"
            }

            MouseArea {
                id: mouseArea5
                anchors.fill: parent
                onPressed: effectButton5Label.text = "jo!"
            }
        }

        Rectangle {
            id: effectButton6
            height: 200
            width: 300
            x: 900
            y: 800

            Label {
                id: effectButton6Label
                text: "Effekt 6"
            }

            MouseArea {
                id: mouseArea6
                anchors.fill: parent
                onPressed: effectButton6Label.text = "jo!"
            }
        }
    }

    Rectangle {
        id: interactiveField
        height: 700
        width: 1300
        x: 2600
        y: 1600
        color: "#aaaaff"

        Label {
            id: interactiveFieldLabel
            anchors.centerIn: parent
            anchors.fill: parent
            text: "Interactive Field"
        }

        MouseArea {
            id: interactiveFieldMouseArea
            anchors.fill: parent
            onPressed: interactiveFieldLabel.text = "it's interactive!"
        }
    }

    Slider {
        id: crossfader
        x: lane1.x + 400
        y: 1400
        width: 800
    }

    Rectangle {
        height: 2
        width: 4096
        color: "gray"
        x: 0
        y: 1500
    }


    Audio {
        id: acdc
        source: "../songs/acdc.ogg"
    }

    Audio {
        id: nirvana
        source: "../songs/nirvana.ogg"
    }

    Audio {
        id: player2
    }

    Label {
        id: songLabel
        x: 200
        y: 400
        width: 650
        height: 160
        text: "asdf asdf"
        rotation: -20
    }
    /*
    PushButton {
        id: addNameButton
        x: 850
        y: 550
        width: 400
        height: 150
        text: "Add my Name!"
        onPressed: {
            helloLabel.text += " from Adrian"
        }
    }

}
*/
