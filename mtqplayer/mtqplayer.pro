TARGET = MTQPlayer

QT *= core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT *= widgets quick
SOURCES += \
    main.cpp \
    plugins/input/Shortcut.cpp \
    plugins/system/Config.cpp \
    plugins/widgets/AngleSlider.cpp \
    plugins/widgets/BaseWidget.cpp \
    plugins/widgets/DebugWidget.cpp \
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
    plugins/widgets/ToggleButton.cpp

HEADERS += \
    plugins/input/Shortcut.h \
    plugins/system/Config.h \
    plugins/widgets/AngleSlider.h \
    plugins/widgets/BaseWidget.h \
    plugins/widgets/DebugWidget.h \
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
    plugins/widgets/ToggleButton.h

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
    resources/config/mtqplayer.ini

INCLUDEPATH += include

LIBS += -L$${PWD}/lib -lMultiToeQt

QMAKE_POST_LINK = cp $${PWD}/lib/libMultiToeQt.so $${OUT_PWD}/libMultiToeQt.so.1 && cp -r $${PWD}/lib/plugins $${OUT_PWD}/plugins && cp -r $${PWD}/data $${OUT_PWD}/data
