#include "TextField.h"

#include <QPainter>
#include <algorithm>

#include "Design.h"

#define MARGIN 10
#define PADDING 25

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(TextField)

//A TextField, used in the TextInputWidget to display, and edit typed text
TextField::TextField(QQuickItem *parent)
	: BaseWidget(parent)
{
	init();
	setWidth(200);
}

//Constructor in case of variable width
TextField::TextField(QQuickItem *parent, const int width)
	: BaseWidget(parent)
{
	init();
	setWidth(width);
}

void TextField::init()
{
	setHeight(120);
	m_paintedText = "";
	m_cursorPosition = 0;

	m_showCursor = true;
	m_cursorBlinkTimer.setInterval(500);
	m_cursorBlinkTimer.setSingleShot(false);
	connect(&m_cursorBlinkTimer, SIGNAL(timeout()), this, SLOT(blink()));
	m_cursorBlinkTimer.start();
}

void TextField::addCharacter(QString text)
{
	if (text == "←") {
		m_paintedText.remove(m_cursorPosition-1,1);
		m_cursorPosition--;
	}
	else if (text == "↵") {
		emit enterPressed();
	}
	else {
		m_paintedText.insert(m_cursorPosition,text);
		m_cursorPosition++;
	}
	update();
}

void TextField::paint(QPainter *painter)
{
	//Draw rect
	painter->setPen(QPen(QBrush(design::normalColor),8));
	painter->drawRect(QRect(MARGIN, MARGIN, width() - 2*MARGIN, height() - 2*MARGIN));

	//Draw text
	m_fontForPaintedText = design::labelFont;
	painter->setFont(m_fontForPaintedText);
	painter->setPen(design::labelFontColor);
	painter->drawText(QRect(MARGIN + PADDING,
							MARGIN + PADDING,
							 width() - 2*MARGIN - 2*PADDING,
							height() - 2*MARGIN - 2*PADDING),
					 Qt::AlignLeft, m_paintedText);

	QFontMetrics font(m_fontForPaintedText);
	int cursorX;
	if (m_cursorPosition > 0)
		cursorX = font.width(m_paintedText.left(m_cursorPosition));
	else
		cursorX = 0;
	if (m_showCursor){
		painter->setPen(QPen(QBrush(design::labelFontColor),3));
		painter->drawLine(MARGIN + PADDING + cursorX, MARGIN + PADDING,
							MARGIN + PADDING + cursorX, height() - MARGIN - PADDING);
	}
}

void TextField::positionTextCursor(const int xInTextRect) {
	//QFontMetric enables us to find out the width of a given QString
	QFontMetrics fontWidth(m_fontForPaintedText);
	for (int i = 1; i < m_paintedText.size(); i++) {
		int stringWidth = fontWidth.width(m_paintedText.left(i-1))
							+ fontWidth.width(m_paintedText.at(i))/2;
		if (xInTextRect < stringWidth) {
			m_cursorPosition = i - 1;
			break;
		}
		else if (i + 1 == m_paintedText.size()) {
			if (xInTextRect < fontWidth.width(m_paintedText.left(i)))
				m_cursorPosition = i;
			else
				m_cursorPosition = i + 1;
		}
	}
	update();
}


void TextField::blink()
{
	m_showCursor = !m_showCursor;
	update();
}

void TextField::processTapDown(mtq::TapEvent *event) {
    positionTextCursor(event->mappedCenter().x() - MARGIN - PADDING);
}

QString TextField::text() const
{
	return m_paintedText;
}

void TextField::setText(const QString &text)
{
	m_paintedText = text;
	update();
}
