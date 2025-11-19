#include "obp_panels.h"
#include <QFrame>

OBP_Panels::OBP_Panels(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    //right side

    h_layout_top = new QHBoxLayout(this);

    button_manual_mode = new PushButton("white","MANUAL\nMODE",01,h_layout_top);
    button_ok = new PushButton("white","OK",02,h_layout_top);
    dial = new QDial();
    dial->setMinimum(25);
    h_layout_top->addWidget(dial);
    v_layout_up_down = new QVBoxLayout();

    button_up = new PushButton("white","MENU\n UP",03,v_layout_up_down);
    button_down = new PushButton("white","MENU\n DOWN",04,v_layout_up_down);

    h_layout_top->addLayout(v_layout_up_down);
    // h_layout_top->setSpacing(20);

    //---------

    lcd_number = new QLineEdit();
    lcd_number->setMinimumWidth(250);
    lcd_number->setMinimumHeight(80);
    lcd_number->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    lcd_number->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    h_layout_stab_ret_orf = new QHBoxLayout(this);
    stab_button = new PushButton("white","STAB\n ON/OFF",04,h_layout_stab_ret_orf);
    ret_button = new PushButton("white","RET\n BRIGHT",05,h_layout_stab_ret_orf);
    orf_button = new PushButton("white","ORF",06,h_layout_stab_ret_orf);

    h_layout_ele_btn_vcr = new QHBoxLayout(this);
    ele_button = new PushButton("white","STAB\n ELE",07,h_layout_ele_btn_vcr);
    btn_button = new PushButton("white","BTN\n BRIGHT",8,h_layout_ele_btn_vcr);
    vcr_button = new PushButton("white","VCR",8,h_layout_ele_btn_vcr);

    h_layout_azi_oled_lrf = new QHBoxLayout(this);
    azi_button = new PushButton("white","STAB\n AZI+\n ELE",9,h_layout_azi_oled_lrf);
    oled_button = new PushButton("white","OLED\n BRIGHT",10,h_layout_azi_oled_lrf);
    lrf_button = new PushButton("white","LRF\n ENABLE",10,h_layout_azi_oled_lrf);

    h_layout_mot_heat_spare = new QHBoxLayout(this);
    mot_button = new PushButton("white","MOT\n AZ",11,h_layout_mot_heat_spare);
    heat_button = new PushButton("white","HEAT\n OCU",12,h_layout_mot_heat_spare);
    spare_button = new PushButton("white","SPARE",13,h_layout_mot_heat_spare);
    // h_layout_mot_heat_spare->addSpacing(50);

    h_layout_win_spareTwo = new QHBoxLayout(this);
    win_button = new PushButton("white","HEAT\n WIN",14,h_layout_win_spareTwo);
    spareTwo_button = new PushButton("white","SPARE",14,h_layout_win_spareTwo);

    v_layout_buttons = new QVBoxLayout(this);
    v_layout_buttons->addLayout(h_layout_stab_ret_orf);
    v_layout_buttons->addLayout(h_layout_ele_btn_vcr);
    v_layout_buttons->addLayout(h_layout_azi_oled_lrf);
    v_layout_buttons->addLayout(h_layout_win_spareTwo);


    v_layout_lcd_buttons = new QVBoxLayout(this);
    v_layout_lcd_buttons->addWidget(lcd_number,0,Qt::AlignCenter);
    v_layout_lcd_buttons->addLayout(v_layout_buttons);
    // v_layout_lcd_buttons->setStretch(0,1);
    // v_layout_lcd_buttons->setStretch(1,2);
    frame = new QFrame();
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Raised);
    frame->setLineWidth(2);
    frame->setLayout(v_layout_lcd_buttons);



    v_layout_obp = new QVBoxLayout(this);
    v_layout_obp->addLayout(h_layout_top);
    v_layout_obp->addWidget(frame);
    // v_layout_obp->setSpacing(20);
    v_layout_obp->setStretch(0,1);
    v_layout_obp->setStretch(1,2);

    //left side

    v_layout_menu_up_down = new QVBoxLayout(this);
    menu_up_button = new PushButton("white","MENU\n UP",01,v_layout_menu_up_down);
    menu_down_button = new PushButton("white","MENU\n DOWN",02,v_layout_menu_up_down);

    h_layout_dial_ok = new QHBoxLayout(this);
    dial_left = new QDial();
    h_layout_dial_ok->addWidget(dial_left);
    ok_button = new PushButton("white","OK",03,h_layout_dial_ok);

    h_layout_menu_dial = new QHBoxLayout();
    h_layout_menu_dial->addLayout(v_layout_menu_up_down);
    h_layout_menu_dial->addLayout(h_layout_dial_ok);
    h_layout_menu_dial->setSpacing(20);

    line_edit_left = new QLineEdit();
    line_edit_left->setMinimumWidth(250);
    line_edit_left->setMinimumHeight(80);
    line_edit_left->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    line_edit_left->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



    h_lAYOUT_view_split_camera = new QHBoxLayout(this);
    direct_view_button = new PushButton("white","DIRECT\n VIEW",04,h_lAYOUT_view_split_camera);
    split_button = new PushButton("white","SPLIT",05,h_lAYOUT_view_split_camera);
    camera_view_button = new PushButton("white","CAMERA\n VIEW",06,h_lAYOUT_view_split_camera);

    h_layout_filter_one_focus_llltv = new QHBoxLayout(this);
    filter_one_button = new PushButton("white","FILTER\n I",07,h_layout_filter_one_focus_llltv);
    focus_button = new PushButton("white","FOCUS",8,h_layout_filter_one_focus_llltv);
    llltv_button = new PushButton("white","LLLTV",9,h_layout_filter_one_focus_llltv);

    h_layout_filter_two_pol_ir = new QHBoxLayout(this);
    filter_two_button = new PushButton("white","FILTER\n II",10,h_layout_filter_two_pol_ir);
    filter_pol_button = new PushButton("white","FILTER\n POL",11,h_layout_filter_two_pol_ir);
    ir_button = new PushButton("white","IR",12,h_layout_filter_two_pol_ir);

    h_layout_filter_three_no_hdtv = new QHBoxLayout(this);
    filter_three_button = new PushButton("white","FILTER\n III",13,h_layout_filter_three_no_hdtv);
    no_filter_button = new PushButton("white","NO\n FILTER",14,h_layout_filter_three_no_hdtv);
    hdtv_button = new PushButton("white","HDTV",15,h_layout_filter_three_no_hdtv);

    v_layout_left_buttons = new QVBoxLayout();
    v_layout_left_buttons->addLayout(h_lAYOUT_view_split_camera);
    v_layout_left_buttons->addLayout(h_layout_filter_one_focus_llltv);
    v_layout_left_buttons->addLayout(h_layout_filter_two_pol_ir);
    v_layout_left_buttons->addLayout(h_layout_filter_three_no_hdtv);
    v_layout_left_buttons->sizeConstraint();

    v_layout_line_button = new QVBoxLayout();
    v_layout_line_button->addWidget(line_edit_left,0,Qt::AlignCenter);
    v_layout_line_button->addLayout(v_layout_left_buttons);

    frame_left = new QFrame();
    frame_left->setFrameShape(QFrame::Box);
    frame_left->setFrameShadow(QFrame::Raised);
    frame_left->setLineWidth(2);
    frame_left->setLayout(v_layout_line_button);

    v_layout_main_left = new QVBoxLayout();
    v_layout_main_left->addLayout(h_layout_menu_dial);
    v_layout_main_left->addWidget(frame_left);
    // v_layout_main_left->setSpacing(20);
    v_layout_main_left->setStretch(0,1);
    v_layout_main_left->setStretch(1,2);

    h_layout = new QHBoxLayout();
    h_layout->addLayout(v_layout_main_left);
    h_layout->addLayout(v_layout_obp);
    // h_layout->setSpacing(20);

    central_widget->setLayout(h_layout);

}

OBP_Panels::~OBP_Panels()
{

}
