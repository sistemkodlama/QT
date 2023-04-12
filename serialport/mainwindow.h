#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>      // Serial Port kütüphanesi eklenir
#include <QSerialPortInfo>  // QSerialPort class'ına port bilgisini gönderebilmek için

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort serialport; // QSerialPort objesi oluşturulur
    QSerialPortInfo serialport_info;

    void init_combobox_ports(const QList<QSerialPortInfo>& ports);
private:
    Ui::MainWindow *ui;

public slots:
    void onStartClicked();
    void onFinishClicked();
    void read();
    void write();
};
#endif // MAINWINDOW_H
