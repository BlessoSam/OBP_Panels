#include "obp_panels.h"
#include <QFrame>

OBP_Panels::OBP_Panels(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    //right side

    h_layout_top = new QHBoxLayout(this);

    button_manual_mode = new PushButton("white","MANUAL\nMODE",01,this);
    button_manual_mode->setCheckable(true);
    button_ok = new PushButton("white","OK",02,this);
    button_ok->setCheckable(true);
    dial = new QDial();
    dial->setMinimum(25);
    dial->setFixedSize(120,120);
    button_up = new PushButton("white","MENU\nUP",03,this);
    button_up->setCheckable(true);
    button_down = new PushButton("white","MENU\nDOWN",04,this);
    button_down->setCheckable(true);

    h_layout_ok_dialog = new QHBoxLayout(this);
    h_layout_ok_dialog->addWidget(button_ok);
    h_layout_ok_dialog->addWidget(dial);
    v_layout_up_down = new QVBoxLayout(this);
    v_layout_up_down->addWidget(button_up);
    v_layout_up_down->addWidget(button_down);

    h_layout_top->addWidget(button_manual_mode);
    h_layout_top->addLayout(h_layout_ok_dialog);
    h_layout_top->addLayout(v_layout_up_down);
    h_layout_top->setSpacing(20);
    h_layout_top->addSpacing(25);


    //---------

    lcd_number = new QLineEdit();
    lcd_number->setMinimumWidth(250);
    lcd_number->setMinimumHeight(80);
    lcd_number->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    lcd_number->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    h_layout_stab_ret_orf = new QHBoxLayout(this);
    stab_button = new PushButton("white","STAB\n ON/OFF",05,this);
    stab_button->setCheckable(true);
    ret_button = new PushButton("white","RET\n BRIGHT",06,this);
    ret_button->setCheckable(true);
    orf_button = new PushButton("white","ORF",07,this);
    orf_button->setCheckable(true);
    h_layout_stab_ret_orf->addWidget(stab_button);
    h_layout_stab_ret_orf->addWidget(ret_button);
    h_layout_stab_ret_orf->addWidget(orf_button);

    h_layout_ele_btn_vcr = new QHBoxLayout(this);
    ele_button = new PushButton("white","STAB\n ELE",8,this);
    ele_button->setCheckable(true);
    btn_button = new PushButton("white","BTN\n BRIGHT",9,this);
    btn_button->setCheckable(true);
    vcr_button = new PushButton("white","VCR",10,this);
    vcr_button->setCheckable(true);
    h_layout_ele_btn_vcr->addWidget(ele_button);
    h_layout_ele_btn_vcr->addWidget(btn_button);
    h_layout_ele_btn_vcr->addWidget(vcr_button);

    h_layout_azi_oled_lrf = new QHBoxLayout(this);
    azi_button = new PushButton("white","STAB\n AZI+\n ELE",11,this);
    azi_button->setCheckable(true);
    oled_button = new PushButton("white","OLED\n BRIGHT",12,this);
    oled_button->setCheckable(true);
    lrf_button = new PushButton("white","LRF\n ENABLE",13,this);
    lrf_button->setCheckable(true);
    h_layout_azi_oled_lrf->addWidget(azi_button);
    h_layout_azi_oled_lrf->addWidget(oled_button);
    h_layout_azi_oled_lrf->addWidget(lrf_button);

    h_layout_mot_heat_spare = new QHBoxLayout(this);
    mot_button = new PushButton("white","MOT\n AZ",14,this);
    mot_button->setCheckable(true);
    heat_button = new PushButton("white","HEAT\n OCU",15,this);
    heat_button->setCheckable(true);
    spare_button = new PushButton("white","SPARE",16,this);
    spare_button->setCheckable(true);
    h_layout_mot_heat_spare->addWidget(mot_button);
    h_layout_mot_heat_spare->addWidget(heat_button);
    h_layout_mot_heat_spare->addWidget(spare_button);
    // // h_layout_mot_heat_spare->addSpacing(50);

    h_layout_win_spareTwo = new QHBoxLayout(this);
    win_button = new PushButton("white","HEAT\n WIN",17,this);
    win_button->setCheckable(true);
    spareTwo_button = new PushButton("white","SPARE",18,this);
    spareTwo_button->setCheckable(true);
    h_layout_win_spareTwo->addWidget(win_button);
    h_layout_win_spareTwo->addWidget(spareTwo_button);

    v_layout_buttons = new QVBoxLayout(this);
    v_layout_buttons->addLayout(h_layout_stab_ret_orf);
    v_layout_buttons->addLayout(h_layout_ele_btn_vcr);
    v_layout_buttons->addLayout(h_layout_azi_oled_lrf);
    v_layout_buttons->addLayout(h_layout_mot_heat_spare);
    v_layout_buttons->addLayout(h_layout_win_spareTwo);


    v_layout_lcd_buttons = new QVBoxLayout(this);
    v_layout_lcd_buttons->addWidget(lcd_number,0,Qt::AlignCenter);
    v_layout_lcd_buttons->addLayout(v_layout_buttons);
    v_layout_lcd_buttons->setSpacing(6);
    v_layout_lcd_buttons->setStretch(0,2);
    v_layout_lcd_buttons->setStretch(1,1);
    frame = new QFrame();
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Raised);
    frame->setLineWidth(2);
    frame->setLayout(v_layout_lcd_buttons);



    v_layout_obp = new QVBoxLayout(this);
    v_layout_obp->addLayout(h_layout_top);
    v_layout_obp->addWidget(frame);
    v_layout_obp->setStretch(0,1);
    v_layout_obp->setStretch(1,2);
    v_layout_obp->addSpacing(25);



    //left side

    v_layout_menu_up_down = new QVBoxLayout(this);
    menu_up_button = new PushButton("white","MENU\n UP",01,this);
    menu_up_button->setCheckable(true);
    menu_down_button = new PushButton("white","MENU\n DOWN",02,this);
    menu_down_button->setCheckable(true);
    v_layout_menu_up_down->addWidget(menu_up_button);
    v_layout_menu_up_down->addWidget(menu_down_button);

    h_layout_dial_ok = new QHBoxLayout(this);
    dial_left = new QDial();
    dial_left->setMinimum(25);
    dial_left->setFixedSize(120,120);
    ok_button = new PushButton("white","OK",03,this);
    ok_button->setCheckable(true);
    h_layout_dial_ok->addWidget(dial_left);
    h_layout_dial_ok->addWidget(ok_button);

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
    direct_view_button = new PushButton("white","DIRECT\n VIEW",04,this);
    direct_view_button->setCheckable(true);
    split_button = new PushButton("white","SPLIT",05,this);
    split_button->setCheckable(true);
    camera_view_button = new PushButton("white","CAMERA\n VIEW",06,this);
    camera_view_button->setCheckable(true);
    h_lAYOUT_view_split_camera->addWidget(direct_view_button);
    h_lAYOUT_view_split_camera->addWidget(split_button);
    h_lAYOUT_view_split_camera->addWidget(camera_view_button);

    h_layout_filter_one_focus_llltv = new QHBoxLayout(this);
    filter_one_button = new PushButton("white","FILTER\n I",07,this);
    filter_one_button->setCheckable(true);
    focus_button = new PushButton("white","FOCUS",8,this);
    focus_button->setCheckable(true);
    llltv_button = new PushButton("white","LLLTV",9,this);
    llltv_button->setCheckable(true);
    h_layout_filter_one_focus_llltv->addWidget(filter_one_button);
    h_layout_filter_one_focus_llltv->addWidget(focus_button);
    h_layout_filter_one_focus_llltv->addWidget(llltv_button);

    h_layout_filter_two_pol_ir = new QHBoxLayout(this);
    filter_two_button = new PushButton("white","FILTER\n II",10,this);
    filter_two_button->setCheckable(true);
    filter_pol_button = new PushButton("white","FILTER\n POL",11,this);
    filter_pol_button->setCheckable(true);
    ir_button = new PushButton("white","IR",12,this);
    ir_button->setCheckable(true);
    h_layout_filter_two_pol_ir->addWidget(filter_two_button);
    h_layout_filter_two_pol_ir->addWidget(filter_pol_button);
    h_layout_filter_two_pol_ir->addWidget(ir_button);

    h_layout_filter_three_no_hdtv = new QHBoxLayout(this);
    filter_three_button = new PushButton("white","FILTER\n III",13,this);
    filter_three_button->setCheckable(true);
    no_filter_button = new PushButton("white","NO\n FILTER",14,this);
    no_filter_button->setCheckable(true);
    hdtv_button = new PushButton("white","HDTV",15,this);
    hdtv_button->setCheckable(true);
    h_layout_filter_three_no_hdtv->addWidget(filter_three_button);
    h_layout_filter_three_no_hdtv->addWidget(no_filter_button);
    h_layout_filter_three_no_hdtv->addWidget(hdtv_button);

    v_layout_left_buttons = new QVBoxLayout(this);
    v_layout_left_buttons->addLayout(h_lAYOUT_view_split_camera);
    v_layout_left_buttons->addLayout(h_layout_filter_one_focus_llltv);
    v_layout_left_buttons->addLayout(h_layout_filter_two_pol_ir);
    v_layout_left_buttons->addLayout(h_layout_filter_three_no_hdtv);
    v_layout_left_buttons->sizeConstraint();

    v_layout_line_button = new QVBoxLayout();
    v_layout_line_button->addWidget(line_edit_left,0,Qt::AlignCenter);
    v_layout_line_button->addLayout(v_layout_left_buttons);
    v_layout_line_button->setSpacing(40);

    frame_left = new QFrame();
    frame_left->setFrameShape(QFrame::Box);
    frame_left->setFrameShadow(QFrame::Raised);
    frame_left->setLineWidth(2);
    frame_left->setLayout(v_layout_line_button);

    v_layout_main_left = new QVBoxLayout();
    v_layout_main_left->addLayout(h_layout_menu_dial);
    v_layout_main_left->addWidget(frame_left);
    v_layout_main_left->setSpacing(20);
    v_layout_main_left->setStretch(0,1);
    v_layout_main_left->setStretch(1,2);
    v_layout_main_left->addSpacing(25);

    h_layout = new QHBoxLayout();
    h_layout->addLayout(v_layout_main_left);
    h_layout->addLayout(v_layout_obp);
    h_layout->setSpacing(20);
    // h_layout->addSpacing(25);
    // central_widget->setStyleSheet({"background-color:lightblue"});

    central_widget->setLayout(h_layout);



    //END UI----------
    thread = new QThread(this);
    worker = new Worker();
    worker->moveToThread(thread);
    connect(thread,&QThread::started,worker,&Worker::init);
    connect(button_manual_mode,&PushButton::clicked,this,&OBP_Panels::on_manual_mode_btn_clicked);
    connect(button_ok,&QPushButton::clicked,this,&OBP_Panels::on_ok_btn_clicked);
    connect(button_up,&QPushButton::clicked,this,&OBP_Panels::on_menu_up_btn_clicked);
    connect(button_down,&QPushButton::clicked,this,&OBP_Panels::on_menu_down_btn_clicked);
    connect(stab_button,&QPushButton::clicked,this,&OBP_Panels::on_stab_btn_clicked);
    connect(ret_button,&QPushButton::clicked,this,&OBP_Panels::on_redbright_btn_clicked);
    connect(orf_button,&QPushButton::clicked,this,&OBP_Panels::on_orf_btn_clicked);
    connect(ele_button,&QPushButton::clicked,this,&OBP_Panels::on_ele_btn_clicked);
    connect(btn_button,&QPushButton::clicked,this,&OBP_Panels::on_bright_btn_clicked);
    connect(vcr_button,&QPushButton::clicked,this,&OBP_Panels::on_vcr_btn_clicked);
    connect(azi_button,&QPushButton::clicked,this,&OBP_Panels::on_azi_btn_clicked);
    connect(oled_button,&QPushButton::clicked,this,&OBP_Panels::on_oled_btn_clicked);
    connect(lrf_button,&QPushButton::clicked,this,&OBP_Panels::on_lrf_btn_clicked);
    connect(mot_button,&QPushButton::clicked,this,&OBP_Panels::on_mot_btn_clicked);
    connect(heat_button,&QPushButton::clicked,this,&OBP_Panels::on_head_btn_clicked);
    connect(spare_button,&QPushButton::clicked,this,&OBP_Panels::on_spare_btn_clicked);
    connect(win_button,&QPushButton::clicked,this,&OBP_Panels::on_head_win_btn_clicked);
    connect(spareTwo_button,&QPushButton::clicked,this,&OBP_Panels::on_spare_two_btn_clicked);

    connect(menu_up_button,&QPushButton::clicked,this,&OBP_Panels::on_menu_up_button_clicked);
    connect(menu_down_button,&QPushButton::clicked,this,&OBP_Panels::on_menu_down_button_clicked);
    connect(ok_button,&QPushButton::clicked,this,&OBP_Panels::on_ok_button_clicked);
    connect(direct_view_button,&QPushButton::clicked,this,&OBP_Panels::on_direct_view_button_clicked);
    connect(split_button,&QPushButton::clicked,this,&OBP_Panels::on_split_button_clicked);
    connect(camera_view_button,&QPushButton::clicked,this,&OBP_Panels::on_camera_view_button_clicked);
    connect(filter_one_button,&QPushButton::clicked,this,&OBP_Panels::on_filter_one_button_clicked);
    connect(focus_button,&QPushButton::clicked,this,&OBP_Panels::on_focus_button_clicked);
    connect(llltv_button,&QPushButton::clicked,this,&OBP_Panels::on_llltv_button_clicked);
    connect(filter_two_button,&QPushButton::clicked,this,&OBP_Panels::on_filter_two_button_clicked);
    connect(filter_pol_button,&QPushButton::clicked,this,&OBP_Panels::on_filter_pol_button_clicked);
    connect(ir_button,&QPushButton::clicked,this,&OBP_Panels::on_ir_button_clicked);
    connect(filter_three_button,&QPushButton::clicked,this,&OBP_Panels::on_filter_three_button_clicked);
    connect(no_filter_button,&QPushButton::clicked,this,&OBP_Panels::on_no_filter_button_clicked);
    connect(hdtv_button,&QPushButton::clicked,this,&OBP_Panels::on_hdtv_button_clicked);

    connect(this,&OBP_Panels::sendData,worker,&Worker::sendMessage);
    connect(thread,&QThread::finished,worker,&QObject::deleteLater);
    thread->start();

}

OBP_Panels::~OBP_Panels()
{
    if(thread->isRunning()){
        thread->quit();
        thread->wait();
    }
}

void OBP_Panels::on_manual_mode_btn_clicked()
{
    if(button_manual_mode->isChecked()){
        qDebug()<<"manual";
        button_manual_mode->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(button_manual_mode->get_serail_number());
        qDebug()<<button_manual_mode->get_serail_number();
    }
    else
    {
       button_manual_mode->setStyleSheet("background-color: white; color: black;border-radius:50px;border:7px solid black");
    }

}

void OBP_Panels::on_ok_btn_clicked()
{
    if(button_ok->isChecked()){
        qDebug()<<"ok";
        button_ok->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(button_ok->get_serail_number());
        qDebug()<<button_ok->get_serail_number();
    }
    else
    {
        button_ok->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_menu_up_btn_clicked()
{
    if(button_up->isChecked()){

        button_up->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(button_up->get_serail_number());
        qDebug()<<button_up->get_serail_number();
    }
    else
    {
        button_up->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }

}

void OBP_Panels::on_menu_down_btn_clicked()
{
    if(button_down->isChecked()){
        qDebug()<<"ok";
        button_down->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(button_down->get_serail_number());
        qDebug()<<button_down->get_serail_number();
    }
    else
    {
        button_down->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }

}

void OBP_Panels::on_stab_btn_clicked()
{
    if(stab_button->isChecked()){
        qDebug()<<"ok";
        stab_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(stab_button->get_serail_number());
        qDebug()<<stab_button->get_serail_number();
    }
    else
    {
        stab_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_redbright_btn_clicked()
{
    if(ret_button->isChecked()){
        qDebug()<<"ok";
        ret_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(ret_button->get_serail_number());
        qDebug()<<ret_button->get_serail_number();
    }
    else
    {
        ret_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_orf_btn_clicked()
{
    if(orf_button->isChecked()){
        qDebug()<<"ok";
        orf_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(orf_button->get_serail_number());
        qDebug()<<orf_button->get_serail_number();
    }
    else
    {
        orf_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_ele_btn_clicked()
{
    if(ele_button->isChecked()){
        qDebug()<<"ok";
        ele_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(ele_button->get_serail_number());
        qDebug()<<ele_button->get_serail_number();
    }
    else
    {
        ele_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_bright_btn_clicked()
{
    if(btn_button->isChecked()){
        qDebug()<<"ok";
        btn_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(btn_button->get_serail_number());
        qDebug()<<btn_button->get_serail_number();
    }
    else
    {
        btn_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_vcr_btn_clicked()
{
    if(vcr_button->isChecked()){
        qDebug()<<"ok";
        vcr_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(vcr_button->get_serail_number());
        qDebug()<<vcr_button->get_serail_number();
    }
    else
    {
        vcr_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_azi_btn_clicked()
{
    if(azi_button->isChecked()){
        qDebug()<<"ok";
        azi_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(azi_button->get_serail_number());
        qDebug()<<azi_button->get_serail_number();
    }
    else
    {
        azi_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_oled_btn_clicked()
{
    if(oled_button->isChecked()){
        qDebug()<<"ok";
        oled_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(oled_button->get_serail_number());
        qDebug()<<oled_button->get_serail_number();
    }
    else
    {
        oled_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_lrf_btn_clicked()
{
    if(lrf_button->isChecked()){
        qDebug()<<"ok";
        lrf_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(lrf_button->get_serail_number());
        qDebug()<<lrf_button->get_serail_number();
    }
    else
    {
        lrf_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_mot_btn_clicked()
{
    if(mot_button->isChecked()){
        qDebug()<<"ok";
        mot_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(mot_button->get_serail_number());
        qDebug()<<mot_button->get_serail_number();
    }
    else
    {
        mot_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_head_btn_clicked()
{
    if(heat_button->isChecked()){
        qDebug()<<"ok";
        heat_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(heat_button->get_serail_number());
        qDebug()<<heat_button->get_serail_number();
    }
    else
    {
        heat_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_spare_btn_clicked()
{
    if(spare_button->isChecked()){
        qDebug()<<"ok";
        spare_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(spare_button->get_serail_number());
        qDebug()<<spare_button->get_serail_number();
    }
    else
    {
        spare_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_head_win_btn_clicked()
{
    if(win_button->isChecked()){
        qDebug()<<"ok";
        win_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(win_button->get_serail_number());
        qDebug()<<win_button->get_serail_number();
    }
    else
    {
        win_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_spare_two_btn_clicked()
{
    if(spareTwo_button->isChecked()){
        qDebug()<<"ok";
        spareTwo_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(spareTwo_button->get_serail_number());
        qDebug()<<spareTwo_button->get_serail_number();
    }
    else
    {
        spareTwo_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

//left side

void OBP_Panels::on_menu_up_button_clicked()
{
    if(menu_up_button->isChecked()){
        qDebug()<<"ok";
        menu_up_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(menu_up_button->get_serail_number());
        qDebug()<<menu_up_button->get_serail_number();
    }
    else
    {
        menu_up_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_menu_down_button_clicked()
{
    if(menu_down_button->isChecked()){
        qDebug()<<"ok";
        menu_down_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(menu_down_button->get_serail_number());
        qDebug()<<menu_down_button->get_serail_number();
    }
    else
    {
        menu_down_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_ok_button_clicked()
{
    if(ok_button->isChecked()){
        qDebug()<<"ok";
        ok_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(ok_button->get_serail_number());
        qDebug()<<ok_button->get_serail_number();
    }
    else
    {
        ok_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_direct_view_button_clicked()
{
    if(direct_view_button->isChecked()){
        qDebug()<<"ok";
        direct_view_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(direct_view_button->get_serail_number());
        qDebug()<<direct_view_button->get_serail_number();
    }
    else
    {
        direct_view_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_split_button_clicked()
{
    if(split_button->isChecked()){
        qDebug()<<"ok";
        split_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(split_button->get_serail_number());
        qDebug()<<split_button->get_serail_number();
    }
    else
    {
        split_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_camera_view_button_clicked()
{
    if(camera_view_button->isChecked()){
        qDebug()<<"ok";
        camera_view_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(camera_view_button->get_serail_number());
        qDebug()<<camera_view_button->get_serail_number();
    }
    else
    {
        camera_view_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_filter_one_button_clicked()
{
    if(filter_one_button->isChecked()){
        qDebug()<<"ok";
        filter_one_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(filter_one_button->get_serail_number());
        qDebug()<<filter_one_button->get_serail_number();
    }
    else
    {
        filter_one_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_focus_button_clicked()
{
    if(focus_button->isChecked()){
        qDebug()<<"ok";
        focus_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(focus_button->get_serail_number());
        qDebug()<<focus_button->get_serail_number();
    }
    else
    {
        focus_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_llltv_button_clicked()
{
    if(llltv_button->isChecked()){
        qDebug()<<"ok";
        llltv_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(llltv_button->get_serail_number());
        qDebug()<<llltv_button->get_serail_number();
    }
    else
    {
        llltv_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_filter_two_button_clicked()
{
    if(filter_two_button->isChecked()){
        qDebug()<<"ok";
        filter_two_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(filter_two_button->get_serail_number());
        qDebug()<<filter_two_button->get_serail_number();
    }
    else
    {
        filter_two_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_filter_pol_button_clicked()
{
    if(filter_pol_button->isChecked()){
        qDebug()<<"ok";
        filter_pol_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(filter_pol_button->get_serail_number());
        qDebug()<<filter_pol_button->get_serail_number();
    }
    else
    {
        filter_pol_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_ir_button_clicked()
{
    if(ir_button->isChecked()){
        qDebug()<<"ok";
        ir_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(ir_button->get_serail_number());
        qDebug()<<ir_button->get_serail_number();
    }
    else
    {
        ir_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_filter_three_button_clicked()
{
    if(filter_three_button->isChecked()){
        qDebug()<<"ok";
        filter_three_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(filter_three_button->get_serail_number());
        qDebug()<<filter_three_button->get_serail_number();
    }
    else
    {
        filter_three_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_no_filter_button_clicked()
{
    if(no_filter_button->isChecked()){
        qDebug()<<"ok";
        no_filter_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(no_filter_button->get_serail_number());
        qDebug()<<no_filter_button->get_serail_number();
    }
    else
    {
        no_filter_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}

void OBP_Panels::on_hdtv_button_clicked()
{
    if(hdtv_button->isChecked()){
        qDebug()<<"ok";
        hdtv_button->setStyleSheet({"background-color:red;border-radius:50px;border:4px solid white"});
        emit sendData(hdtv_button->get_serail_number());
        qDebug()<<hdtv_button->get_serail_number();
    }
    else
    {
        hdtv_button->setStyleSheet("background-color:white;border-radius:50px;color:black;border:7px solid black");
    }
}
