#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400,600);
    setWindowTitle("QPushButton Example");

    btn_ok = new QPushButton("OK");
    ui->centralwidget->setLayout(new QVBoxLayout());
    ui->centralwidget->layout()->addWidget(btn_ok);

    btn_cancel = new QPushButton();
    btn_cancel->setText("Cancel");      // Buton text 'ini sonradan set etmek için
    btn_cancel->setEnabled(false);      // Butonu disable durumuna getiririz
    ui->centralwidget->layout()->addWidget(btn_cancel);

    btn_green = new QPushButton("Green");
    btn_green->setStyleSheet("background-color: green; color: white");  // Butonun renklerini belirtiriz
    ui->centralwidget->layout()->addWidget(btn_green);

    btn_click = new QPushButton("Click");
    ui->centralwidget->layout()->addWidget(btn_click);

    connect(btn_ok, &QPushButton::clicked, this, &MainWindow::on_btnOKClicked);           // buton tıklandığında
    connect(btn_cancel, &QPushButton::pressed, this, &MainWindow::on_btnCancelPressed);   // buton üstüne basıldığı anda
    connect(btn_green, &QPushButton::released, this, &MainWindow::on_btnGreenReleased);    // buton üstüne basılmayı kaldırdığımız anda
    connect(btn_click, &QPushButton::clicked,
            btn_click, [&](){
                            if(btn_click->text() == "Click") {
                                btn_click->setText("Wait");
                            }
                            else if(btn_click->text() == "Wait") {
                                btn_click->setText("Click");
                        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOKClicked()
{
    qDebug() << "Buton-OK tıklandı";
}

void MainWindow::on_btnCancelPressed()
{
    qDebug() << "Buton-Cancel basıldı";
}

void MainWindow::on_btnGreenReleased()
{
    qDebug() << "Buton-Green bırakıldı";
}

