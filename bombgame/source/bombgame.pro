TARGET = BombGame

QT *= core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT *= widgets quick

SOURCES += \
    main.cpp \
    plugins/widgets/BombGame.cpp \
    plugins/widgets/BaseWidget.cpp

HEADERS += \
    plugins/widgets/BombGame.h \
    plugins/widgets/BaseWidget.h \
    plugins/widgets/SendHighscore.inc

RESOURCES += \
    resources/bombgame.qrc

OTHER_FILES += \
    resources/fonts/Ubuntu-L.ttf \
    resources/fonts/Ubuntu-R.ttf \
    resources/img/bomb.png \
    resources/img/timer.png \
    resources/img/get_ready.png \
    resources/img/game_over.png \
    resources/img/digit_9.png \
    resources/img/digit_8.png \
    resources/img/digit_7.png \
    resources/img/digit_6.png \
    resources/img/digit_5.png \
    resources/img/digit_4.png \
    resources/img/digit_3.png \
    resources/img/digit_2.png \
    resources/img/digit_1.png \
    resources/img/digit_0.png \
    resources/img/boom.png \
    resources/img/bomb_lit.png \
    resources/img/bomb.png \
    resources/qml/PanZoom.qml \
    resources/config/bombgame.ini

INCLUDEPATH += include

LIBS += -L$${PWD}/lib -lMultiToeQt

QMAKE_POST_LINK = cp $${PWD}/lib/libMultiToeQt.so $${OUT_PWD}/libMultiToeQt.so.1 && cp -r $${PWD}/lib/plugins $${OUT_PWD}/plugins && cp -r $${PWD}/config.ini $${OUT_PWD}/config.ini
