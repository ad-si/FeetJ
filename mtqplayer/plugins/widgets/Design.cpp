#include "Design.h"

namespace design {

    //The baseDir(this depends on your execution directory)
    const QString baseDir("widgets/");

    const QString widgetsSvgFile("://svg/Widgets.svg");

    //The labelFont
    const QFont labelFont("Ubuntu Light", 32, QFont::Light);
    const QColor labelFontColor(238,238,238);

    const QFont debugFont("Ubuntu Light", 15, QFont::Light);

    //The captionFont
    const QFont captionFont("Ubuntu Light", 36, QFont::DemiBold);

    //Color for dark text on bright background
    const QColor darkTextColor(0,0,0);

    //The foreground Color
    const QColor normalColor(136,136,136);

    //The highlighted foreground Color
    const QColor activeColor(204,204,207);

    const int borderWidth = 8;

    const int borderRadius = 40;

}
