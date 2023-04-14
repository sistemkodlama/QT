#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel *label_welcome;

    void textRenginiDegistir(QString color);
    void arkaplanRenginiDegistir(QString color);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
