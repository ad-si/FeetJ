import QtQuick 2.0
import mtq.widgets 1.0

Item {
    width: 1800
    height: 2400

    Lane {
        id: lane1
        anchors.left: parent.left
    }

    Lane {
        id: lane2
        anchors.right: parent.right
    }

    Crossfader {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 1600
    }
}
