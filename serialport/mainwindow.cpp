#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // serialport için kullanılacak port adresinin belirlenmesi için
    // mevcut port'ların listesi çıkarılır,
    // sonra bu portlar comboBox'a yazılır
    QList<QSerialPortInfo> all_ports = serialport_info.availablePorts();
    init_combobox_ports(all_ports);

    ///////// Serial Port Configuration //////////
    // set baudrate
    serialport.setBaudRate(QSerialPort::Baud115200);
    // set flow control
    serialport.setFlowControl(QSerialPort::NoFlowControl);
    // set data bits
    serialport.setDataBits(QSerialPort::Data8);
    // set stop bits
    serialport.setStopBits(QSerialPort::OneStop);
    // set parity
    serialport.setParity(QSerialPort::NoParity);


    // connections
    connect(ui->btn_start, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->btn_finish, &QPushButton::clicked, this, &MainWindow::onFinishClicked);
    connect(&serialport, &QSerialPort::readyRead, this, &MainWindow::read);
    connect(ui->btn_send, &QPushButton::clicked, this, &MainWindow::write);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_combobox_ports(const QList<QSerialPortInfo>& ports)
{
    // ilk eleman seçim yapınız ibaresi olsun
    ui->comboBox_ports->insertItem(0, "Lütfen bir port seçin...");

    int comboBox_index=1;
    for(auto i : ports) {
        ui->comboBox_ports->insertItem(comboBox_index, i.portName());
        comboBox_index++;
    }
}

void MainWindow::onStartClicked()
{
    // öncelikle port adresini set edelim
    QString portName = ui->comboBox_ports->currentText();
    serialport.setPortName("/dev/ttyUSB1");

    // seri haberleşmeyi başlat
    if(serialport.open(QIODeviceBase::ReadWrite)) {
        qDebug() << "Bilgi : Serialport bağlantısı başarı ile sağlandı!";
    }
    else {
        qDebug() << "Hata : Serialport açılamadı...";
    }
}

void MainWindow::onFinishClicked()
{
    serialport.close();
}

void MainWindow::read()
{
    QString text = serialport.readAll();
    ui->plainTextEdit->insertPlainText(text);
}

void MainWindow::write()
{
    QString text = ui->lineEdit_message->text();
    serialport.write(text.toStdString().c_str());   // QString 'i (char*) tipi string 'e dönüştür
}
