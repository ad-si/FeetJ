import QtQuick 2.0
import QtMultimedia 5.0
import mtq.widgets 1.0
//import fb.player 1.0 //wtf


Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"
    property var songsAdded: 0

    FjSlider {
        id: crossfader
        x: 1748
        y: 1500
        width: 700
        height: 300
        onValueChanged: {
            if (crossfader.value < 0.5) {
                player.crossfade(1,2, crossfader.value);
            } else {
                player.crossfade(2,1, crossfader.value);
            }
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
        x: 1448
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
        x: 1148
        y: 1100
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
                if (floor.songsAdded == 0) {
                    player.setVolume(1,1);
                } else {
                    player.setVolume(1,0);
                }

                floor.songsAdded++;

                laneImageChubby.visible = true
                songPicker.visible = false
            }
            else if (selectedItem == 1) {
                player.changeTrack(1,1);
                if (floor.songsAdded == 0) {
                    player.setVolume(1,1);
                } else {
                    player.setVolume(1,0);
                }

                floor.songsAdded++;
                laneImageParov.visible = true
                songPicker.visible = false
            }
            else if (selectedItem == 2) {
                player.changeTrack(1,0);
                if (floor.songsAdded == 0) {
                    player.setVolume(1,1);
                } else {
                    player.setVolume(1,0);
                }

                floor.songsAdded++;
                laneImageBeach.visible = true
                songPicker.visible = false
            }

        }
    }


    PushButton {
        id: laneImageChubby
        x: 1448
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
        x: 1448
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
        x: 1448
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
        x: 2548
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
        x: 2248
        y: 1100
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
                if (floor.songsAdded == 0) {
                    player.setVolume(2,1);
                } else {
                    player.setVolume(2,0);
                }

                floor.songsAdded++;

                laneImageChubby2.visible = true
                songPicker2.visible = false
            }
            else if (selectedItem == 1) {
                player.changeTrack(2,1);
                if (floor.songsAdded == 0) {
                    player.setVolume(2,1);
                } else {
                    player.setVolume(2,0);
                }

                floor.songsAdded++;
                laneImageParov2.visible = true
                songPicker2.visible = false
            }
            else if (selectedItem == 2) {
                player.changeTrack(2,0);
                if (floor.songsAdded == 0) {
                    player.setVolume(2,1);
                } else {
                    player.setVolume(2,0);
                }

                floor.songsAdded++;
                laneImageBeach2.visible = true
                songPicker2.visible = false
            }

        }
    }


    PushButton {
        id: laneImageChubby2
        x: 2548
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
        x: 2548
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
        x: 2548
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
        id: flanger1
        x: 20
        y: 400
        height: 150
        width: 300
        visible: true
        text: 'flanger'
        onMtqTapDown: {
            player.toggleEffect(1,1);
        }
    }

    PushButton {
        id: wah1
        x: 20
        y: 580
        height: 150
        width: 300
        visible: true
        text: 'wahwahwaaaa'
        onMtqTapDown: {
            player.toggleEffect(1,4);
        }
    }

    PushButton {
        id: phaser1
        x: 20
        y: 760
        height: 150
        width: 300
        visible: true
        text: 'PHAZZZER!!!!'
        onMtqTapDown: {
            player.toggleEffect(1,5);
        }
    }


    PushButton {
        id: chorus1
        x: 20
        y: 940
        height: 150
        width: 300
        visible: true
        text: 'khorus'
        onMtqTapDown: {
            player.toggleEffect(1,6);
        }
    }

    PushButton {
        id: reverb1
        x: 20
        y: 1120
        height: 150
        width: 300
        visible: true
        text: 'reverb'
        onMtqTapDown: {
            player.toggleEffect(1,2);
        }
    }

    PushButton {
        id: gargle1
        x: 20
        y: 1300
        height: 150
        width: 300
        visible: true
        text: 'gargle'
        onMtqTapDown: {
            player.toggleEffect(1,3);
        }
    }

    GenericButton {
       id: controlPad1
       x: 400
       y: 500
       height: 800
       width: 700
       visible: true
       onMtqTapDown: {
           player.modifyEffect(1,event.mappedCenter.x/3, event.mappedCenter.y/3);
           controlPadMarker1.x = event.mappedCenter.x -18;
           controlPadMarker1.y = event.mappedCenter.y -18;

       }
       Rectangle {
           id: controlPadMarker1
           height: 36
           width: 36
           color: 'black'
           x: 150-18
           y: 150-18
           visible: true

        }
    }

    PushButton {
        id: flanger2
        x: 3776
        y: 400
        height: 150
        width: 300
        visible: true
        text: 'flanger'
        onMtqTapDown: {
            player.toggleEffect(2,1);
        }
    }

    PushButton {
        id: wah2
        x: 3776
        y: 580
        height: 150
        width: 300
        visible: true
        text: 'wahwahwaaaa'
        onMtqTapDown: {
            player.toggleEffect(2,4);
        }
    }

    PushButton {
        id: phaser2
        x: 3776
        y: 760
        height: 150
        width: 300
        visible: true
        text: 'PHAZZZER!!!!'
        onMtqTapDown: {
            player.toggleEffect(2,5);
        }
    }


    PushButton {
        id: chorus2
        x: 3776
        y: 940
        height: 150
        width: 300
        visible: true
        text: 'khorus'
        onMtqTapDown: {
            player.toggleEffect(2,6);
        }
    }

    PushButton {
        id: reverb2
        x: 3776
        y: 1120
        height: 150
        width: 300
        visible: true
        text: 'reverb'
        onMtqTapDown: {
            player.toggleEffect(2,2);
        }
    }

    PushButton {
        id: gargle2
        x: 3776
        y: 1300
        height: 150
        width: 300
        visible: true
        text: 'gargle'
        onMtqTapDown: {
            player.toggleEffect(2,3);
        }
    }

    GenericButton {
       id: controlPad2
       x: 2996
       y: 500
       height: 800
       width: 700
       visible: true
       onMtqTapDown: {
           player.modifyEffect(2,event.mappedCenter.x/3, event.mappedCenter.y/3);
           controlPadMarker2.x = event.mappedCenter.x -18;
           controlPadMarker2.y = event.mappedCenter.y -18;

       }
       Rectangle {
           id: controlPadMarker2
           height: 36
           width: 36
           color: 'black'
           x: 150-18
           y: 150-18
           visible: true

        }
    }

}
