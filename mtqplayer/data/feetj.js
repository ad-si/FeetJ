var config = {
        visible: false
    }


function configurate(configObject){

    for(var key in configObject)
        if(configObject.hasOwnProperty(key))
            config[key] = config[key] || configObject[key]
}

function addSongPickerTo(parent){

    var songPicker,
        instance

    function finishCreation() {

         if (songPicker.status === Component.Ready) {

             instance = songPicker.createObject(parent, config)

             instance.x -= instance.pickerWidth/2
             instance.y -= instance.pickerHeight/2

             instance.visible = true

             if (instance === null)
                 console.log("Error creating object")

         }
         else if (component.status === Component.Error)
             console.log("Error loading component:", component.errorString())
     }

    songPicker = Qt.createComponent("Songpicker.qml")

    if (songPicker.status === Component.Ready)
        finishCreation()
    else
        songPicker.statusChanged.connect(finishCreation)
}

function loadSong(song){

    console.log(song.name)
}
