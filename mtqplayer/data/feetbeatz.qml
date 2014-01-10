import QtQuick 2.0
import QtMultimedia 5.0
import mtq.widgets 1.0
//import fb.player 1.0 //wtf

Rectangle {
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
    */
}
