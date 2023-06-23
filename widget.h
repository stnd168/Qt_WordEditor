#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_Clear_clicked();

    void on_checkBox_Bold_clicked(bool checked);

    void on_checkBox_Italic_clicked(bool checked);

    void on_checkBox_Underline_clicked(bool checked);

    void on_spinBox_Size_valueChanged(int arg1);

    // 變更顏色
    void do_FontColor();


    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
