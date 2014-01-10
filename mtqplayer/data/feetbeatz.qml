import QtQuick 2.0
import QtMultimedia 5.0
import mtq.widgets 1.0
//import "audioLogic.js" as audioLogic


Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#333333"

    Lane {
        id: lane1
        x: 0
        laneColor: "#ffaaaa"
    }

    Lane {
        id: lane2
        x: 2000
        laneColor: "#aaffaa"
    }

    Crossfader {}

    Rectangle {
        id: nowLine
        height: 2
        width: 4096
        color: "gray"
        x: 0
        y: 1500
    }
}
