import QtQuick 2.0
import mtq.widgets 1.0

Item {
    width: 1800
    height: 2400

    Lane {
        id: lane1
        anchors.left: parent.left
        //laneColor: "#ffaaaa"
        waveHeight: 2400
    }

    Lane {
        id: lane2
        anchors.right: parent.right
        //laneColor: "#aaffaa"
        waveHeight: 2400
    }

    Crossfader {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 1600
    }
}
