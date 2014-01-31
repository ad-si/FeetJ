TARGET = MTQPlayer

QT *= core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT *= widgets quick
SOURCES += \
    main.cpp \
    plugins/input/Shortcut.cpp \
    plugins/system/Config.cpp \
    plugins/widgets/AngleSlider.cpp \
    plugins/widgets/BaseWidget.cpp \
    plugins/widgets/Design.cpp \
    plugins/widgets/EventConsole.cpp \
    plugins/widgets/GenericSvgButton.cpp \
    plugins/widgets/Keyboard.cpp \
    plugins/widgets/Label.cpp \
    plugins/widgets/ListPicker.cpp \
    plugins/widgets/PaintField.cpp \
    plugins/widgets/PushButton.cpp \
    plugins/widgets/RadioButton.cpp \
    plugins/widgets/Slider.cpp \
    plugins/widgets/TextField.cpp \
    plugins/widgets/TextInputWidget.cpp \
    plugins/widgets/ToggleButton.cpp \
    plugins/widgets/GenericButton.cpp \
    plugins/widgets/FjSlider.cpp \
    plugins/widgets/FjPlayer.cpp \
    soundMain.cpp \
    player.cpp \
    song.cpp \
    songlist.cpp

HEADERS += \
    plugins/input/Shortcut.h \
    plugins/system/Config.h \
    plugins/widgets/AngleSlider.h \
    plugins/widgets/BaseWidget.h \
    plugins/widgets/Design.h \
    plugins/widgets/EventConsole.h \
    plugins/widgets/GenericSvgButton.h \
    plugins/widgets/Keyboard.h \
    plugins/widgets/Label.h \
    plugins/widgets/ListPicker.h \
    plugins/widgets/PaintField.h \
    plugins/widgets/PushButton.h \
    plugins/widgets/RadioButton.h \
    plugins/widgets/Slider.h \
    plugins/widgets/TextField.h \
    plugins/widgets/TextInputWidget.h \
    plugins/widgets/ToggleButton.h \
    plugins/widgets/GenericButton.h \
    plugins/widgets/FjSlider.h \
    plugins/widgets/FjPlayer.h \
    include/bass/bass.h \
    soundMain.h \
    player.h \
    plugins/widgets/FjSlider.h \
    plugins/widgets/FjPlayer.h \
    song.h \
    songlist.h \
    include/bass/bass_fx.h


RESOURCES += \
    resources/mtqplayer.qrc

OTHER_FILES += \
    resources/fonts/Ubuntu-L.ttf \
    resources/fonts/Ubuntu-R.ttf \
    resources/svg/Widgets.svg \
    resources/qml/PanZoom.qml \
    resources/qml/PanZoomLoader.js \
    qml/WidgetDemo.qml \
    qml/Paint.qml \
    qml/HelloWorld.qml \
    resources/config/mtqplayer.ini \
    config.ini \
    data/audioLogic.js \
    data/Lane.qml \
    data/Test.qml \
    data/Songpicker.qml \
    data/Crossfader.qml \
    data/DjArea.qml \
    data/FeetJ.qml \
    data/feetbeatz.qml \
    data/EffectArea.qml \
    data/EffectPad.qml \
    data/EffectControls.qml \
    data/Song.qml \
    data/feettest.qml

INCLUDEPATH += include

LIBS += -L$${PWD}/lib -lMultiToeQt

QMAKE_POST_LINK = ln -s $${PWD}/lib/libMultiToeQt.so $${OUT_PWD}/libMultiToeQt.so.1 && ln -s $${PWD}/lib/plugins $${OUT_PWD}/plugins && ln -s $${PWD}/data $${OUT_PWD}/data && ln -s $${PWD}/qml $${OUT_PWD}/qml && ln -s $${PWD}/config.ini $${OUT_PWD}/config.ini

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/bass/release/ -lbass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/bass/debug/ -lbass
else:unix: LIBS += -L$$PWD/include/bass/ -lbass

INCLUDEPATH += $$PWD/include/bass
DEPENDPATH += $$PWD/include/bass


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/bass/release/ -lbass_fx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/bass/debug/ -lbass_fx
else:unix: LIBS += -L$$PWD/include/bass/ -lbass_fx

INCLUDEPATH += $$PWD/include/bass
DEPENDPATH += $$PWD/include/bass
