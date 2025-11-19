#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QResizeEvent>
#include <QDebug>
#include <QLayout>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QString color, QString text, uint16_t serial_number, QLayout *parent = nullptr);

private:
    QString color;
    QString text;
    int serial_number;
    QPushButton *button;

    void resizeEvent(QResizeEvent *event) override;



public:
    QString get_color();
    QString get_text();
    uint16_t get_serail_number();
};

#endif // PUSHBUTTON_H
