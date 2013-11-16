import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"


	
    Label {
        id: helloLabel
		x: 200
		y: 400
        width: 650
        height: 160
		text: "Hello World"
		rotation: -20
    }

    PushButton {
		id: addNameButton
		x: 850
		y: 550
		width: 400
		height: 150
		text: "Add my Name!"
		onPressed: { /* it's JavaScript in here! */
			helloLabel.text += " from <your name>"
		}
    }

}
