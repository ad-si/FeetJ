import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"
	

	
	PushButton {
		id: dummyCatchall
		x: 0
		y: 0
		text: "tt"
		height: 2400
		width: 4096
		onQmlContactMove: {
			//	console.log("test");
			//console.log(event.x());
			//console.log(event.center.x);
			fun.x = event.center.x;
			fun.y = event.center.y;
		}

		onQmlTapDown: {
		fan.x = event.center.x;
		fan.y = event.center.y;
		}
	}


	
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
	/*DebugWidget {
	height: 2400
	width: 4096
	}*/
	Rectangle {
		id: fun
		color: "#00ff00"
		width: 100
		height: 100
	}

	Rectangle {
		id: fan
		color: "#ff0000"
		width: 100
		height: 100
	}

	/*TextInputWidget {
		x: 20
		y: 10

	}*/

}
