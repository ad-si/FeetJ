import QtQuick 2.0
import mtq.widgets 1.0
import mtq.input 1.0
import mtq.system 1.0
import "PanZoomLoader.js" as PanZoomLoader

Rectangle {
	id: background
	color: "black"
	x: 0
	y: 0


	Rectangle {

		/* Do not be alarmed;
		 *	you are looking for the QML filename, which was called statically here.
		 *	It has been raised; it is not here. Look, there is the place we laid it.
		 *	But go, tell the disciples and Jakob that it is going ahead of you to a
		 *	command line parameter. There you will see it, just as we told you.
		 */

		id: contentToBeMoved
		width: 4096
		height: 2400
		Scale {
			id: viewScale;
			xScale: 1;
			yScale: 1;
			origin.x: 0
			origin.y: 0
		}
        Translate {id: viewTranslate; x: 0; y: 0}
		transform: [viewTranslate, viewScale ]


		Config {
			id: config
		}

        Component.onCompleted: {PanZoomLoader.createChildObject("file://" + config.value("Qml"));}
	}

	//Minimap
	Rectangle {
		id: minimapFrame
		height: contentToBeMoved.height * 0.03
		width: contentToBeMoved.width * 0.03
		x: background.width - 10 - (contentToBeMoved.width * 0.03)
		y: 10
		color: "#50ffffff"
		border.color: "#80ffffff"
		border.width: 2
	}

	Rectangle {
		id: minimapScreen
		height: (background.height * 0.03) / viewScale.yScale
		width: background.width * 0.03 / viewScale.xScale
		color: "#50303030"
		border.color: "#80ffffff"
		border.width: 2
		x: background.width - 10 - (contentToBeMoved.width * 0.03)
			- (viewTranslate.x * 0.03)
		y: 10
			- (viewTranslate.y * 0.03)
	}


	GenericSvgButton {
		id: moveUpButton
		x: 50
		y: 10
		width: 40
		height: 40
		svgElementId: "ZoomPan::w"
		onPressed: {viewTranslate.y-=40;}
	}
	GenericSvgButton {
		id: moveLeftButton
		x: 10
		y: 50
		width: 40
		height: 40
		svgElementId: "ZoomPan::a"
		onPressed: {viewTranslate.x-=40;}
	}
	GenericSvgButton {
		id: moveRightButton
		x: 90
		y: 50
		width: 40
		height: 40
		svgElementId: "ZoomPan::d"
		onPressed: {viewTranslate.x+=40; }
	}
	GenericSvgButton {
		id:  moveDownButton
		x: 50
		y: 90
		width: 40
		height: 40
		svgElementId: "ZoomPan::s"
		onPressed: {viewTranslate.y+=40; }
	}
	GenericSvgButton {
		id: zoomOutButton
		x: 10
		y: 140
		width: 40
		height: 40
		svgElementId: "ZoomPan::-"
		onPressed: {
			var oldXDistance =  (background.width/2 - (viewTranslate.x * viewScale.xScale));
			var oldYDistance =  (background.height/2 - (viewTranslate.y * viewScale.yScale));
			viewScale.xScale *= 1./1.2;
			viewScale.yScale *= 1./1.2;
			viewTranslate.x = (background.width/2 - oldXDistance/1.2) / viewScale.xScale;
			viewTranslate.y = (background.height/2 - oldYDistance/1.2) / viewScale.yScale;
		}
	}
	GenericSvgButton {
		id: resetViewButton
		x: 50
		y: 140
		width: 40
		height: 40
		svgElementId: "ZoomPan::1"
		onPressed: {
			viewTranslate.x=0;
			viewTranslate.y=0;
			viewScale.xScale = 1;
			viewScale.yScale = 1;
		}
	}
	GenericSvgButton {
		id: zoomInButton
		x: 90
		y: 140
		width: 40
		height: 40
		svgElementId: "ZoomPan::plus"
		onPressed: {
			var oldXDistance =  (background.width/2 - (viewTranslate.x * viewScale.xScale));
			var oldYDistance =  (background.height/2 - (viewTranslate.y * viewScale.yScale));
			viewScale.xScale *= 1.2;
			viewScale.yScale *= 1.2;
			viewTranslate.x = (background.width/2 - oldXDistance*1.2) / viewScale.xScale;
			viewTranslate.y = (background.height/2 - oldYDistance*1.2) / viewScale.yScale;
        }
	}

	Shortcut {key: "+"; onActivated: {zoomInButton.onPressed()} }
	Shortcut {key: "-"; onActivated: {zoomOutButton.onPressed()} }
	Shortcut {key: "q"; onActivated: {zoomInButton.onPressed()} }
	Shortcut {key: "e"; onActivated: {zoomOutButton.onPressed()} }
	Shortcut {key: "w"; onActivated: {moveUpButton.onPressed()} }
	Shortcut {key: "s"; onActivated: {moveDownButton.onPressed()} }
	Shortcut {key: "a"; onActivated: {moveLeftButton.onPressed()} }
	Shortcut {key: "d"; onActivated: {moveRightButton.onPressed()} }
	Shortcut {key: "1"; onActivated: {resetViewButton.onPressed()} }
}
