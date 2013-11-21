#pragma once

#include <QTextEdit>

#include "BaseWidget.h"

class TextField: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(TextField, "widgets")

public:
	TextField(QQuickItem *parent = 0);
	TextField(QQuickItem *parent, const int width);

	void paint(QPainter *painter);

	QString text() const;
	void setText(const QString &text);

private:
	QString m_paintedText;
	int m_cursorPosition;
	QTimer m_cursorBlinkTimer;
	bool m_showCursor;
	QFont m_fontForPaintedText;

	void positionTextCursor(const int xInText);
	void init();

public slots:
	void addCharacter(QString text);
	void blink();

protected:
    void processTapDown(mtq::TapEvent *event);

signals:
	void enterPressed();
};
