#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 重要!!手動建立連接
    // connect(觸動元件, 信號, 響應元件, 響應事件)
    connect(ui->radioButton_Black, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Red, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Blue, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Green, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Yellow, SIGNAL(clicked()), this, SLOT(do_FontColor()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_Clear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_checkBox_Bold_clicked(bool checked)
{
    // 取得plainTextEdit font內容
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_checkBox_Italic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_checkBox_Underline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Widget::on_spinBox_Size_valueChanged(int arg1)
{
    QFont font = ui->plainTextEdit->font();
    font.setPixelSize(arg1);
    ui->plainTextEdit->setFont(font);
}

void Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    QFont font = ui->plainTextEdit->font();
    font.setFamily(arg1);
    ui->plainTextEdit->setFont(font);
}

void Widget::do_FontColor()
{
    // 取得調色盤
    QPalette palette = ui->plainTextEdit->palette();

    // 判斷哪個單選框被選中
    if(ui->radioButton_Black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    if(ui->radioButton_Red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    if(ui->radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    if(ui->radioButton_Green->isChecked())
        palette.setColor(QPalette::Text, Qt::green);
    if(ui->radioButton_Yellow->isChecked())
        palette.setColor(QPalette::Text, Qt::yellow);

    // 更改字體顏色
    ui->plainTextEdit->setPalette(palette);

    // 注意: 自創事件，寫好後要手動將函式與介面連接( 寫在 Widget::Widget 中)
}



