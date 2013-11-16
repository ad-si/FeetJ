#pragma once

#include <QTextEdit>

#include "BaseWidget.h"

using namespace mtq;

class TextField: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(TextField, "widgets")

public:
	TextField(QQuickItem *parent = 0);
	TextField(QQuickItem *parent, int width);

	void paint(QPainter *painter);

	QString text();
	void setText(const QString &text);

private:
	QString m_paintedText;
	int m_cursorPosition;
	QTimer m_cursorBlinkTimer;
	bool m_showCursor;
	QFont m_fontForPaintedText;

	void positionTextCursor(int xInText);
	void init();

public slots:
	void addCharacter(QString text);
	void blink();

protected:
	void mousePressEvent(QMouseEvent *event);
	void tapDown(TapEvent *event);

signals:
	void enterPressed();
};
