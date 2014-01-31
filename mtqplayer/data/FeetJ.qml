import QtQuick 2.0
import mtq.widgets 1.0
//import "audioLogic.js" as audioLogic


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
        anchors.horizontalCenter: parent.horizontalCenter
    }

    EffectArea {
        anchors.right: parent.right
    }
}


