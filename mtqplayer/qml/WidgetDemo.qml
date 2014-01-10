import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
	id: floor
    width: 4096
    height: 2400
    color: "#ff333333"

	Label {
		id: radioButtonLabel
		x: 1600
		y: 1850
		width: toggleButton.active ? 1000 : 0
		text: "Background Color"
	}

	Label {
		id: helloLabel
		x: 500
        y: 800
        width: 3000
		text: ""
	}


	ToggleButton {
		id: toggleButton
        x: 50
        y: 650
        width: 400
        height: 160
        activeTitle: "ON"
        inactiveTitle: "OFF"
    }


    TextInputWidget{
        id: keyboardOutput
        x: 50
        y: 1700
        width: 1000
    }



    RadioButton {
        id: radioButton
        x: 1500
        y: 2000
        width: toggleButton.active ? 1200 : 0
        selectedItem: 0
        rotation: 5

        Component.onCompleted: {
            radioButton.addItem("gray");
            radioButton.addItem("green");
            radioButton.addItem("blue");
        }

        onSelectedItemChanged: {
            if (selectedItem == 0)
                parent.color = "#ff333333"
            if (selectedItem == 1)
                parent.color = "#ff005500"
            if (selectedItem == 2)
                parent.color = "#ff000055"
        }

	}

    Slider {
        id: slider
        x: 600
        y: 500
        width: 2000*slider2.value + 300
        height: 300
    }


    Slider {
        id: slider2
        x: 600
        y: 800
        width: 2000*slider.value + 300
        value: 0.5
		rotation: angleSlider.value / Math.PI * 180
    }

    AngleSlider {
        id: angleSlider
        x: 3000
        y: 100
        width: 900
        height: 900
        value: 0
    }



    ListPicker {
        id: listPicker
        x: 2500
        y: 100
        width: 400
        height: 400
        selectedItem: 0
        rotation: 5
        caption: "Menu"

        Component.onCompleted: {
			listPicker.addItem("clockwise");
			listPicker.addItem("anticlockwise");
        }

        onSelectedItemChanged: {
			if (selectedItem == 0) {
				rotatingButton.text = "rotate me \nclockwise!"
				rotatingButton.pressed.disconnect(
							rotatingButton.rotateAnticlockwise);
				rotatingButton.pressed.connect(
							rotatingButton.rotateClockwise);
				rotatingButton.update();
			} else if (selectedItem == 1) {
				rotatingButton.text = "rotate me \nanticlockwise!"
				rotatingButton.pressed.disconnect(
							rotatingButton.rotateClockwise);
				rotatingButton.pressed.connect(
							rotatingButton.rotateAnticlockwise);
				rotatingButton.update();
			}
        }
    }


	PushButton {
		id: pushButton
        x: 50
        y: 50
        width: 300
		text: "Hello"
        rotation: 350
        onPressed: {
            helloLabel.text += "Hello! "
        }
    }

    PushButton {
		id: rotatingButton
        x: 50
        y: 300
        width: 300
        height: 250
		text: "rotate me \nclockwise!"

		Component.onCompleted: {
			rotatingButton.pressed.connect(
						rotatingButton.rotateClockwise);
		}

		function rotateClockwise() {
			rotatingButton.rotation +=5;
		}

		function rotateAnticlockwise() {
			rotatingButton.rotation -=5;
		}

	}

/*
    DebugWidget {
        id: debugWidget
        x: 0
        y: 0
        width: 4000
        height: 2000
    }*/
}
