#ifndef OBP_PANELS_H
#define OBP_PANELS_H
#include "pushbutton.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QDial>
#include <QFrame>
class OBP_Panels : public QMainWindow
{
    Q_OBJECT

public:
    OBP_Panels(QWidget *parent = nullptr);
    ~OBP_Panels();

private:
    PushButton *button_manual_mode;
    PushButton *button_ok;
    PushButton *button_up;
    PushButton *button_down;
    QDial *dial;
    QVBoxLayout *v_layout_up_down;
    QHBoxLayout *h_layout_top;
    QHBoxLayout *h_layout_ok_dialog;

    QVBoxLayout *v_layout_lcd_buttons;
    QVBoxLayout *v_layout_buttons;
    QLineEdit *lcd_number;
    PushButton *stab_button;
    PushButton *ret_button;
    PushButton *orf_button;
    PushButton *ele_button;
    PushButton *btn_button;
    PushButton *vcr_button;
    PushButton *azi_button;
    PushButton *oled_button;
    PushButton *lrf_button;
    PushButton *mot_button;
    PushButton *heat_button;
    PushButton *spare_button;
    PushButton *win_button;
    PushButton *spareTwo_button;

    QHBoxLayout *h_layout_stab_ret_orf;
    QHBoxLayout *h_layout_ele_btn_vcr;
    QHBoxLayout*h_layout_azi_oled_lrf;
    QHBoxLayout *h_layout_mot_heat_spare;
    QHBoxLayout *h_layout_win_spareTwo;
    QFrame *frame;
    QVBoxLayout *v_layout_obp;


    //left side

    PushButton *menu_up_button;
    PushButton *menu_down_button;
    QDial *dial_left;
    PushButton *ok_button;
    QLineEdit *line_edit_left;
    PushButton *direct_view_button;
    PushButton *split_button;
    PushButton *camera_view_button;
    PushButton *filter_one_button;
    PushButton *focus_button;
    PushButton *llltv_button;
    PushButton *filter_two_button;
    PushButton *filter_pol_button;
    PushButton *ir_button;
    PushButton *filter_three_button;
    PushButton *no_filter_button;
    PushButton *hdtv_button;

    QVBoxLayout *v_layout_menu_up_down;
    QHBoxLayout *h_layout_dial_ok;
    QHBoxLayout *h_layout_menu_dial;

    QHBoxLayout *h_lAYOUT_view_split_camera;
    QHBoxLayout *h_layout_filter_one_focus_llltv;
    QHBoxLayout *h_layout_filter_two_pol_ir;
    QHBoxLayout *h_layout_filter_three_no_hdtv;
    QVBoxLayout *v_layout_left_buttons;
    QVBoxLayout *v_layout_line_button;
    QVBoxLayout *v_layout_main_left;
    QFrame *frame_left;

    QHBoxLayout *h_layout;

};
#endif // OBP_PANELS_H
