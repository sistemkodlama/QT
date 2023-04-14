#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400,600);
    setWindowTitle("QLabel Example");

    ui->centralwidget->setLayout(new QVBoxLayout());  // Vertical Layout eklendi
    auto centralLayout = ui->centralwidget->layout();

    label_welcome = new QLabel("Welcome");      // yeni bir QLabel objesi oluşturulur
    centralLayout->addWidget(label_welcome);    // QLabel widget'ı layout 'a eklenir

    textRenginiDegistir("white");
    arkaplanRenginiDegistir("black");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textRenginiDegistir(QString color)
{
    QString mevcut_style = label_welcome->styleSheet();
    label_welcome->setStyleSheet(mevcut_style + "; color: " + color);
}

void MainWindow::arkaplanRenginiDegistir(QString color)
{
    QString mevcut_style = label_welcome->styleSheet();
    label_welcome->setStyleSheet(mevcut_style + "; background-color: " + color);
}
