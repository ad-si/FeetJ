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
		onMtqContactMove: {
            moveRect.x = event.mappedCenter.x;
            moveRect.y = event.mappedCenter.y;
		}

		onMtqTapDown: {
			console.log("Tap Down at ", event.center)
			var tapRect = Qt.createQmlObject('import QtQuick 2.0; 	Rectangle {
			id: tapRect
			color: "#00ff00"
			width: 1
			height: 1
			Rectangle {
				color: "#ff0000"
				x: -50
				y: -2.5
				width: 100
				height: 5
				transformOrigin: Item.Center
				rotation: 45
			}
			Rectangle {
				color: "#ff0000"
				x: -50
				y: -2.5
				width: 100
				height: 5
				transformOrigin: Item.Center
				rotation: -45
			}
		}',
				 floor, "dynamicSnippet");
            tapRect.x = event.mappedCenter.x;
            tapRect.y = event.mappedCenter.y;
		}
	}


	


	Rectangle {
		id: moveRect
		color: "#ffffff"
		width: 1
		height: 1
		Rectangle {
			color: "#ffffff"
			x: -50
			y: -2.5
			width: 100
			height: 5
		}
		Rectangle {
			color: "#ffffff"
			x: -2.5
			y: -50
			width: 5
			height: 100
		}

	}

	/*TextInputWidget {
		x: 20
		y: 10

	}*/

}
