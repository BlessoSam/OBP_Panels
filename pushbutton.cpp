#include "pushbutton.h"

PushButton::PushButton(QString color, QString text, uint16_t serial_number, QWidget *parent):QPushButton(parent)
{
    this->color = color;
    this->text = text;
    this->serial_number = serial_number;
    this->setText(text);
    this->setFixedSize(100,100);
    this->setStyleSheet(QString("QPushButton {" "background-color:%1;" "color:black;"  "border-radius:50px;" "border:7px solid black" "}").arg(color));
    // button->setMinimumSize(80,80);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



}

// void PushButton::resizeEvent(QResizeEvent *event)
// {
//     QWidget::resizeEvent(event);
//     // The diameter is the minimum of current width/height to ensure it stays a circle
//     int diameter = std::min(width(), height());
//     // Calculate offsets to center the circular mask within the button's rectangular area
//     int xOff = (width() - diameter) / 2;
//     int yOff = (height() - diameter) / 2;

//     // Apply a circular mask
//     setMask(QRegion(xOff, yOff, diameter, diameter, QRegion::Ellipse));
// }


// void PushButton::resizeEvent(QResizeEvent *event)
// {
//     QPushButton::resizeEvent(event);

//     // Ensure square shape
//     int side = qMin(width(), height());
//     resize(side, side);

//     // Update stylesheet with dynamic radius
//     setStyleSheet(QString(
//                       "QPushButton {"
//                       "border-radius: %1px;"
//                       "background-color:%2;"
//                       "color:black;"
//                       "border: 2px solid darkblue;"
//                       "}").arg(side/2).arg(color));
// }





QString PushButton::get_color()
{
    return color;
}

QString PushButton::get_text()
{
    return text;
}

uint16_t PushButton::get_serail_number()
{
    return serial_number;
}
