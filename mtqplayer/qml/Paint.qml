import QtQuick 2.0
import mtq.widgets 1.0

Rectangle {
    id: floor
    width: 4096
    height: 2400
    color: "#ff333333"

    PaintField	{
        id: paintField
        x: 100
        y: 100
        width: 1200
        height: 1000
		strokeHue: 0.5
		backgroundBrightness: 100
        }
		
	AngleSlider {
		id: hueSlider
		x: 1400
		y: 300
		width: 200
		height: 200
		value: 0
		onValueChanged: {
			paintField.strokeHue = value/2.0/3.141569;
		}
	}
	
	AngleSlider {
		id: brightnessSlider
		x: 1400
		y: 800
		width: 200
		height: 200
		value: 0
		onValueChanged: {
			paintField.backgroundBrightness = value*255/2/3.141569;
		}
	}

}
