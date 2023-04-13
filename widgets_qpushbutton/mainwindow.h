#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>  // Push Button kütüphanesi
#include <QLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QPushButton *btn_green;
    QPushButton *btn_click;

public slots:
    void on_btnOKClicked();
    void on_btnCancelPressed();
    void on_btnGreenReleased();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
