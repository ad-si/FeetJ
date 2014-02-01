import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "black"

    Rectangle {
        id: nowLine
        height: 2
        width: 4096
        color: "gray"
        x: 0
        y: 1500
    }

    DjArea {
        id: djArea
        anchors.horizontalCenter: parent.horizontalCenter
    }

    EffectControls {
        id: effectControls1
        x: 250
        y: 0


    }

    EffectPad {
        id: effectPad1
        x: 350
        y: 500
        height: 800
        width: 700
    }

    EffectPad {
        id: effects2
        x: 3300
        y: 500
        height: 300
        width: 650

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
}
