import QtQuick 2.0
import mtq.widgets 1.0

Item {
    x: 0
    y: 0
    width: 2100
    height: 2400

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

    Crossfader {
        y: 1600
    }

    Rectangle {
        id: nowLine
        height: 2
        width: 4096
        color: "gray"
        x: 0
        y: 1500
    }
}
