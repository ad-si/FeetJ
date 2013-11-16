/*
 * dynamically load a child QML into the panZoom
 * taken from example code at http://qt-project.org/doc/qt-4.8/qdeclarativedynamicobjects.html
 */


var component;
var sprite;

function createChildObject(qmlPath) {
	component = Qt.createComponent(qmlPath);
	if (component.status == Component.Ready)
		finishCreation();
	else
		component.statusChanged.connect(finishCreation);
}

function finishCreation() {
	if (component.status == Component.Ready) {
		sprite = component.createObject(contentToBeMoved);
		if (sprite == null) {
			console.log("Error creating object");
		}
	} else if (component.status == Component.Error) {
		console.log("Error loading component:", component.errorString());
	}
}
