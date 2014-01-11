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
        //laneColor: "#ffaaaa"
        waveHeight: 2400
    }

    Lane {
        id: lane2
        x: 2000
        //laneColor: "#aaffaa"
        waveHeight: 2400
    }

    Crossfader {
        y: 1600
    }
}
